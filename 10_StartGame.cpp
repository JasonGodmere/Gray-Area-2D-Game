
#include "10_Menu.h"

void Menu::StartGame(Textures& textures)
{
	if (worlds.size() == NULL)
	{
		chosenPage = Interface::Menu::NAMEWORLD;
	}

	if (chosenPage == Interface::Menu::STARTGAME &&
		loadedPage != Interface::Menu::STARTGAME)
	{
		UI.clear();
		count = 0;
		while (true)
		{
			//INTERFACE
			Interface interface(textures);

			if (count == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "World Select";
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

			if (count == 1)
			{
				for (int i = 0; i < worlds.size(); i++)
				{
					//world buttons
					interface.type = Interface::Type::WORLDSELECT;
					interface.menu = Interface::Menu::LOADGAME;
					interface.worldSelect = Interface::WorldSelect::STARTWORLD;
					interface.string = worlds[i].worldName;
					interface.worldNum = worlds[i].worldNum;
					interface.characterSize = 50;
					interface.rect.setSize(sf::Vector2f(600, 100));
					interface.rect.setOrigin(300, 50);
					interface.rectColorR = 80;
					interface.rectColorG = 80;
					interface.rectColorB = 80;
					interface.rectColorA = 180;
					interface.posX = 960;
					interface.posY = 320 + (i * 150);
					interface.outlineThickness = 0;
					UI.push_back(interface);
				}
			}

			if (count == 2 && worlds.size() < maxWorlds)
			{
				//New World
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::COLOR;
				interface.menu = Interface::Menu::NAMEWORLD;
				interface.worldSelect = Interface::WorldSelect::NEWWORLD;
				interface.string = "Create New World";
				interface.characterSize = 50;
				interface.rect.setSize(sf::Vector2f(450, 60));
				interface.rect.setOrigin(225, 30);
				interface.rectColorR = 80;
				interface.rectColorG = 80;
				interface.rectColorB = 80;
				interface.rectColorA = 180;
				interface.posX = 960;
				interface.posY = 320 + (worlds.size() * 150);
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}

			if (count == 2)
			{
				//BACK
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::STARTPAGE;
				interface.string = "Back";
				interface.characterSize = 50;
				interface.rectColorR = 0;
				interface.rectColorG = 0;
				interface.rectColorB = 0;
				interface.rectColorA = 0;
				interface.posX = 960;
				interface.posY = 900;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				break;
			}
			++count;
		}
	}
}