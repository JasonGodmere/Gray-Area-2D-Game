
#include "10_Menu.h"

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

	// load some shit here
	if (chosenPage == Interface::Menu::LOADGAME)
	{
		Menu::LoadWorld(font);
		loadedPage = Interface::Menu::LOADGAME;
	}

	if (chosenPage == Interface::Menu::GENERATEWORLD)
	{
		Menu::GenerateWorld(font);
		loadedPage = Interface::Menu::GENERATEWORLD;
	}
}

void Generate(int count, Menu* menu, Player* player, PlayerTextureMap* tmap, sf::RenderWindow* window)
{
	menu->threading = true;
	World world(player, tmap, menu->UI[count].string);
	world.windowX = window->getSize().x;
	world.windowY = window->getSize().y;
	menu->worlds.push_back(world);

	//menu->worldNum = menu->worlds.size() - 1;
	
	//menu->worlds[menu->worldNum].worldNum = menu->worldNum;

	menu->chosenPage = Interface::Menu::STARTGAME;

	menu->threading = false;
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

			std::thread WorldGenerator(Generate, count, this, player, tmap, &window);
			Menu::ThreadDraw(this, clock, controls, chunkStruct, font, player, tmap, window);
			WorldGenerator.join();
			chosenPage = Interface::Menu::STARTGAME;
			break;
		}

		if (UI[count].type == Interface::Type::WORLDSELECT && UI[count].pressed == true &&
			UI[count].menu == Interface::Menu::LOADGAME)
		{
			worldSelected = UI[count].worldNum;
			chosenPage = Interface::Menu::LOADGAME;
		}
		++count;
	}
}

void Menu::ThreadDraw(Menu* menu, Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::Font& font,
	Player *player, PlayerTextureMap *tmap, sf::RenderWindow& window)
{
	while (window.isOpen() && threading == true) {
		window.clear();

		clock->Update(font);
		
		//DRAW - START
		Menu::Update(clock, controls, chunkStruct, window, font, player, tmap);

		//particle sources array
		count2 = 0;
		if (chosenPage != Interface::Menu::INGAME)
		{
			for (particleSourcesIter = particleSources.begin(); particleSourcesIter != particleSources.end(); particleSourcesIter++)
			{
				particleSources[count2].Draw(clock, window);
				++count2;
			}
		}

		//user interface object array
		count2 = 0;
		for (UIIter = UI.begin(); UIIter != UI.end(); UIIter++)
		{
			UI[count2].Draw(controls, window);
		}
		//DRAW - END

		clock->Draw(font, window);

		window.display();
	}
}