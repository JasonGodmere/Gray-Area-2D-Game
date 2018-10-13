
#include "../Menu.h"

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
				interface.position[0] = 960;
				interface.position[1] = 100;
				interface.setTextColor(interface, 30, 30, 30,255);
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.setTextColor(interface,255,255,255,255);
				interface.characterSize = 80;
				UI.push_back(interface);
			}

			if (i == 1)
			{
				//Input world name
				interface.type = Interface::Type::TEXTINPUT;
				interface.menu = Interface::Menu::GENERATEWORLD;
				interface.string = "";
				//interface.string1 = "Generate World";
				interface.characterSize = 50;
				interface.rect.setSize(sf::Vector2f(600, 100));
				interface.rect.setOrigin(300, 50);
				//interface.rect1.setSize(sf::Vector2f(300, 60));
				//interface.rect1.setOrigin(sf::Vector2f(150, 30));
				interface.position[0] = 960;
				interface.position[1] = 400;
				//interface.posX1 = 960;
				//interface.posY1 = 550;
				interface.setRectColor(interface, 80, 80, 80, 220);
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
				interface.position[0] = 960;
				interface.position[1] = 900;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}
		}
	}
}