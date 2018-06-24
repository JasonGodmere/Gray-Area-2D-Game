
#include "Menu.h"

void LoadingScreen(Menu* menu)
{

}

void Menu::LoadWorld(sf::Font &font)
{
	if (chosenPage == Interface::Menu::LOADGAME &&
		loadedPage != Interface::Menu::LOADGAME)
	{
		UI.clear();
		elements = 1;
		for (int i = 0; i < elements; i++)
		{
			//INTERFACE
			Interface interface(font);

			if (i == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "Loading - " + worlds[worldSelected].worldName;
				interface.characterSize = 120;
				interface.posX = 960;
				interface.posY = 100;
				interface.textColorR = 30;
				interface.textColorG = 30;
				interface.textColorB = 30;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.textColorR = 255;
				interface.textColorG = 255;
				interface.textColorB = 255;
				interface.characterSize = 80;
				UI.push_back(interface);
			}
		}
	}

	//std::thread LoadingThread(LoadingScreen, this);

	//after loading sequence
	chosenPage = Interface::Menu::INGAME;
}