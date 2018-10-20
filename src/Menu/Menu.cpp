
#include "Menu.h"

Menu::Menu()
{
	maxWorlds = 4;
	count = 0;

	chosenPage = Page::STARTPAGE;
	loadedPage = Page::NONE;

	//PARTICLE BACKGROUND EFFECT
	ParticleSource particleSource;

	particleSource.position[0] = 960;
	particleSource.position[1] = 1080;
	particleSource.spawnWidth = 1920;
	particleSources.push_back(particleSource);
}

Menu::~Menu()
{
	//thingy
}

void Menu::Update(Physics& physics, Controls& controls, Chunk *chunk, sf::RenderWindow &window, 
	Player *player, Textures& textures)
{
	controls.typing = false;

	if (chosenPage == Page::STARTPAGE)
	{
		Menu::StartPage(textures);
		loadedPage = Page::STARTPAGE;
	}

	if (chosenPage == Page::STARTGAME)
	{
		Menu::StartGame(textures);
		loadedPage = Page::STARTGAME;
	}

	if (chosenPage == Page::NAMEWORLD)
	{
		Menu::NameWorld(textures);
		loadedPage = Page::NAMEWORLD;
	}

	if (chosenPage == Page::INGAME)
	{
		Menu::InGame(physics, controls, chunk, window, player, textures);
		loadedPage = Page::INGAME;
	}

	if (chosenPage == Page::GENERATEWORLD)
	{
		Menu::GenerateWorld(textures);
		loadedPage = Page::GENERATEWORLD;
	}

	if (chosenPage == Page::ACHIEVEMENTS)
	{
		Menu::Achievements(textures);
		loadedPage = Page::ACHIEVEMENTS;
	}

	if (chosenPage == Page::SETTINGS)
	{
		Menu::Settings(textures);
		loadedPage = Page::SETTINGS;
	}

	if (chosenPage == Page::EXIT)
	{
		window.close();
	}

	// load some shit here
	if (chosenPage == Page::LOADGAME)
	{
		Menu::LoadWorld(textures);
		loadedPage = Page::LOADGAME;
	}

	if (chosenPage == Page::GENERATEWORLD)
	{
		Menu::GenerateWorld(textures);
		loadedPage = Page::GENERATEWORLD;
	}
}

void Generate(int count, Menu* menu, Player* player, Textures* textures, sf::RenderWindow& window)
{
	/*menu->threading = true;
	World world(textures, menu->UI[count].string);
	menu->worlds.push_back(world);

	//menu->worldNum = menu->worlds.size() - 1;
	
	//menu->worlds[menu->worldNum].worldNum = menu->worldNum;

	menu->chosenPage = Interface::Menu::STARTGAME;

	menu->threading = false;*/
}

void Menu::Draw(Physics& physics, Controls& controls, Chunk* chunk, Player* player, 
	Textures& textures, sf::RenderWindow& window)
{
	Menu::Update(physics, controls, chunk, window, player, textures);

	//particle sources array
	if (chosenPage != Page::INGAME)
	{
		for (int i = 0; i < particleSources.size(); i++)
		{
			particleSources[i].Draw(physics, window);
		}
	}

	//user interface object array
	for (int i = 0; i < interface.components.size(); i++)
	{
		interface.components[i].Update(controls, window);
		std::cout << interface.components.size() << std::endl;
		if (interface.components[i].getPressed() == true)
		{//is that button pressed? If so do this
			chosenPage = interface.components[i].buttonIndex;
		}

		if (interface.components[i].type == System::Type::TEXT_INPUT && 
			interface.components[i].getPressed() == true &&
			interface.components[i].buttonIndex == Page::GENERATEWORLD)
		{
			//std::thread WorldGenerator(Generate, count, this, player, textures, window);
			//Menu::ThreadDraw(this, physics, controls, chunk, player, textures, window);
			//WorldGenerator.join();

			chosenPage = Page::STARTGAME;
		}
		//this needs to be finished for world selection
		/*if (interface.components[i].type == System::Type::BUTTON_ARRAY && 
			interface.components[i].getPressed() == true &&
			interface.components[i].buttonIndex == Page::LOADGAME)
		{
			worldSelected = interface.components[i].worldNum;
			chosenPage = Interface::Menu::LOADGAME;
		}*/
	}
}

void Menu::ThreadDraw(Menu* menu, Physics& physics, Controls& controls, Chunk *chunk,
	Player *player, Textures& textures, sf::RenderWindow& window)
{
	/*while (window.isOpen() && threading == true) {
		window.clear();

		physics.UpdateClock(textures);
		
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

		window.draw(physics.getText());

		window.display();
	}*/
}