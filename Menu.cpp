
#include "Menu.h"

Menu::Menu()
{
	maxWorlds = 4;
	count = 0;

	chosenPage = Interface::Menu::STARTPAGE;
	loadedPage = Interface::Menu::NONE;

	//PARTICLE BACKGROUND EFFECT
	ParticleSource particleSource;

	particleSource.type = ParticleSource::Type::FIRE;
	particleSource.posX = 960;
	particleSource.posY = 1080;
	particleSource.spawnWidth = 1920;
	particleSources.push_back(particleSource);
}

Menu::~Menu()
{
	//thingy
}

void Menu::Update(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::RenderWindow &window, sf::Font& font, 
	Player *player, PlayerTextureMap *tmap)
{
	controls->typing = false;

	if (chosenPage == Interface::Menu::STARTPAGE)
	{
		Menu::StartPage(font);
		loadedPage = Interface::Menu::STARTPAGE;
	}

	if (chosenPage == Interface::Menu::STARTGAME)
	{
		Menu::StartGame(font);
		loadedPage = Interface::Menu::STARTGAME;
	}

	if (chosenPage == Interface::Menu::NAMEWORLD)
	{
		Menu::NameWorld(font);
		loadedPage = Interface::Menu::NAMEWORLD;
	}

	if (chosenPage == Interface::Menu::INGAME)
	{
		Menu::InGame(clock, controls, chunkStruct, window, font, player, tmap);
		loadedPage = Interface::Menu::INGAME;
	}

	if (chosenPage == Interface::Menu::GENERATEWORLD)
	{
		Menu::GenerateWorld(font);
		loadedPage = Interface::Menu::GENERATEWORLD;
	}

	if (chosenPage == Interface::Menu::ACHIEVEMENTS)
	{
		Menu::Achievements(font);
		loadedPage = Interface::Menu::ACHIEVEMENTS;
	}

	if (chosenPage == Interface::Menu::SETTINGS)
	{
		Menu::Settings(font);
		loadedPage = Interface::Menu::SETTINGS;
	}

	if (chosenPage == Interface::Menu::EXIT)
	{
		window.close();
	}
}

void Generate(int count, Menu* menu, Player* player, PlayerTextureMap* tmap, sf::RenderWindow* window)
{
	World world(player, tmap, menu->UI[count].string);
	world.windowX = window->getSize().x;
	world.windowY = window->getSize().y;
	menu->worlds.push_back(world);
}

void Menu::Draw(Clock* clock, Controls* controls, ChunkStruct* chunkStruct, sf::Font& font, 
	Player* player, PlayerTextureMap* tmap, sf::RenderWindow& window)
{
	Menu::Update(clock, controls, chunkStruct, window, font, player, tmap);

	//particle sources array
	count = 0;
	if (chosenPage != Interface::Menu::INGAME)
	{
		for (particleSourcesIter = particleSources.begin(); particleSourcesIter != particleSources.end(); particleSourcesIter++)
		{
			particleSources[count].Draw(clock, window);
			++count;
		}
	}

	//user interface object array
	count = 0;
	for (UIIter = UI.begin(); UIIter != UI.end(); UIIter++)
	{
		UI[count].Draw(controls, window);

		if (UI[count].pressed == true)
		{
			chosenPage = UI[count].menu;
		}

		if (UI[count].type == Interface::Type::TEXTINPUT && UI[count].pressed == true &&
			UI[count].menu == Interface::Menu::GENERATEWORLD && UI[count].recorded == false)
		{
			UI[count].recorded = true;

			//lambda of world generation for thread
			//Generate(count, player, worlds, tmap, UI, window);

			//world generation thread
			std::thread worldGenerator(Generate, count, this, player, tmap, &window);
			//Menu::GenerateWorld(font);

			//if (worldGenerator.joinable() == true)
			//{
			worldGenerator.join();
			chosenPage == Interface::Menu::STARTGAME;
			//}

			worldNum = worlds.size() - 1;
			worlds[worldNum].worldNum = worldNum;
		}

		if (UI[count].type == Interface::Type::WORLDSELECT && UI[count].pressed == true &&
			UI[count].menu == Interface::Menu::LOADGAME)
		{
			worldSelected = UI[count].worldNum;
		}
		++count;
	}
}