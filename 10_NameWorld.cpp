
#include "10_Menu.h"

void Menu::NameWorld(Textures& textures)
{
	if (chosenPage == Interface::Menu::NAMEWORLD &&
		loadedPage != Interface::Menu::NAMEWORLD)
	{
		UI.clear();
		elements = 3;
		for (int i = 0; i < elements; i++)
		{
			//INTERFACE
			Interface interface(textures);

			if (i == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "Name World";
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

			if (i == 1)
			{
				//Input world name
				interface.type = Interface::Type::TEXTINPUT;
				interface.menu = Interface::Menu::GENERATEWORLD;
				interface.string = "";
				interface.string1 = "Generate World";
				interface.characterSize = 50;
				interface.rect.setSize(sf::Vector2f(600, 100));
				interface.rect.setOrigin(300, 50);
				interface.rect1.setSize(sf::Vector2f(300, 60));
				interface.rect1.setOrigin(sf::Vector2f(150, 30));
				interface.posX = 960;
				interface.posY = 400;
				interface.posX1 = 960;
				interface.posY1 = 550;
				interface.rectColorR = 80;
				interface.rectColorG = 80;
				interface.rectColorB = 80;
				interface.rectColorA = 220;
				interface.rect.setOutlineThickness(3);
				interface.rect.setOutlineColor(sf::Color::White);
				UI.push_back(interface);
			}

			if (i == 2)
			{
				//Cancel
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::STARTPAGE;
				interface.string = "Cancel";
				interface.characterSize = 50;
				interface.posX = 960;
				interface.posY = 900;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}
		}
	}
}