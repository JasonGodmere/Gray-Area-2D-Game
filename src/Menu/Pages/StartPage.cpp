
#include "../Menu.h"

void Menu::StartPage(Textures& textures)
{
	if (chosenPage == Interface::Menu::STARTPAGE && 
		loadedPage != Interface::Menu::STARTPAGE)
	{
		UI.clear();
		elements = 5;
		for (int i = 0; i < elements; i++)
		{
			//INTERFACE
			Interface interface(textures);

			if (i == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "Gray Area";
				interface.characterSize = 150;
				interface.position[0] = 960;
				interface.position[1] = 100;
				interface.textColorR = 30;
				interface.textColorG = 30;
				interface.textColorB = 30;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.textColorR = 255;
				interface.textColorG = 255;
				interface.textColorB = 255;
				interface.characterSize = 100;
				UI.push_back(interface);
			}

			if (i == 1)
			{
				//START GAME
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::STARTGAME;
				interface.string = "Start Game";
				interface.characterSize = 40;
				interface.position[0] = 960;
				interface.position[1] = 300;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}

			if (i == 2)
			{
				//ACHIEVEMENTS
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::ACHIEVEMENTS;
				interface.string = "Achievements";
				interface.characterSize = 40;
				interface.position[0] = 960;
				interface.position[1] = 400;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}

			if (i == 3)
			{
				//SETTINGS
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::SETTINGS;
				interface.string = "Settings";
				interface.characterSize = 40;
				interface.position[0] = 960;
				interface.position[1] = 500;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}

			if (i == 4)
			{
				//EXIT
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::EXIT;
				interface.string = "Exit";
				interface.characterSize = 40;
				interface.position[0] = 960;
				interface.position[1] = 600;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}
		}
	}

	//Update
}