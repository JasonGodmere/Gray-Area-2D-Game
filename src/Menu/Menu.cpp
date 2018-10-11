
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

void Menu::Update(Physics& physics, Controls *controls, Chunk *chunk, sf::RenderWindow &window, 
	Player *player, Textures *textures)
{
	controls->typing = false;

	if (chosenPage == Interface::Menu::STARTPAGE)
	{
		Menu::StartPage(*textures);
		loadedPage = Interface::Menu::STARTPAGE;
	}

	if (chosenPage == Interface::Menu::STARTGAME)
	{
		Menu::StartGame(*textures);
		loadedPage = Interface::Menu::STARTGAME;
	}

	if (chosenPage == Interface::Menu::NAMEWORLD)
	{
		Menu::NameWorld(*textures);
		loadedPage = Interface::Menu::NAMEWORLD;
	}

	if (chosenPage == Interface::Menu::INGAME)
	{
		Menu::InGame(physics, controls, chunk, window, player, textures);
		loadedPage = Interface::Menu::INGAME;
	}

	if (chosenPage == Interface::Menu::GENERATEWORLD)
	{
		Menu::GenerateWorld(*textures);
		loadedPage = Interface::Menu::GENERATEWORLD;
	}

	if (chosenPage == Interface::Menu::ACHIEVEMENTS)
	{
		Menu::Achievements(*textures);
		loadedPage = Interface::Menu::ACHIEVEMENTS;
	}

	if (chosenPage == Interface::Menu::SETTINGS)
	{
		Menu::Settings(*textures);
		loadedPage = Interface::Menu::SETTINGS;
	}

	if (chosenPage == Interface::Menu::EXIT)
	{
		window.close();
	}

	// load some shit here
	if (chosenPage == Interface::Menu::LOADGAME)
	{
		Menu::LoadWorld(*textures);
		loadedPage = Interface::Menu::LOADGAME;
	}

	if (chosenPage == Interface::Menu::GENERATEWORLD)
	{
		Menu::GenerateWorld(*textures);
		loadedPage = Interface::Menu::GENERATEWORLD;
	}
}

void Generate(int count, Menu* menu, Player* player, Textures* textures, sf::RenderWindow* window)
{
	menu->threading = true;
	World world(textures, menu->UI[count].string);
	menu->worlds.push_back(world);

	//menu->worldNum = menu->worlds.size() - 1;
	
	//menu->worlds[menu->worldNum].worldNum = menu->worldNum;

	menu->chosenPage = Interface::Menu::STARTGAME;

	menu->threading = false;
}

void Menu::Draw(Physics& physics, Controls* controls, Chunk* chunk, Player* player, 
	Textures* textures, sf::RenderWindow& window)
{
	Menu::Update(physics, controls, chunk, window, player, textures);

	//particle sources array
	count = 0;
	if (chosenPage != Interface::Menu::INGAME)
	{
		for (particleSourcesIter = particleSources.begin(); particleSourcesIter != particleSources.end(); particleSourcesIter++)
		{
			particleSources[count].Draw(physics, window);
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

			std::thread WorldGenerator(Generate, count, this, player, textures, &window);
			Menu::ThreadDraw(this, physics, controls, chunk, player, textures, window);
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

void Menu::ThreadDraw(Menu* menu, Physics& physics, Controls *controls, Chunk *chunk,
	Player *player, Textures *textures, sf::RenderWindow& window)
{
	while (window.isOpen() && threading == true) {
		window.clear();

		physics.Update(*textures);
		
		//DRAW - START
		Menu::Update(physics, controls, chunk, window, player, textures);

		//particle sources array
		count2 = 0;
		if (chosenPage != Interface::Menu::INGAME)
		{
			for (particleSourcesIter = particleSources.begin(); particleSourcesIter != particleSources.end(); particleSourcesIter++)
			{
				particleSources[count2].Draw(physics, window);
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

		physics.Draw(window);

		window.display();
	}
}