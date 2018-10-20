
#include "../Menu.h"

void Menu::NameWorld(Textures& textures)
{
	if (chosenPage == Page::NAMEWORLD &&
		loadedPage != Page::NAMEWORLD)
	{
		interface.components.clear();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component(textures, "Gray Area", 4);
				component.type = Component::Type::TEXT;
				component.setPosition(960, 100);
				component.setTextColorRef(component, 30, 30, 30, 255);
				component.outlineThickness = 0;
				interface.components.push_back(component);
				//title
				component.setTextColorRef(component, 255, 255, 255, 255);
				component.sizeRatio = 2.6;
				interface.components.push_back(component);
			}

			/* dont forget to put this in an if statement
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
			*/

			if (count == 1)
			{
				//BACK
				Component component(textures, "Cancel", 1);
				component.type = Component::Type::SIZE_BUTTON;
				component.buttonIndex = Page::STARTPAGE;
				component.setPosition(960, 900);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}