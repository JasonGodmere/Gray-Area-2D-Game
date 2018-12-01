
#include "../Menu.h"

void Menu::StartGame(Textures& textures)
{
	if (worlds.size() == NULL)
	{
		chosenPage = Page::STARTPAGE;
	}

	if (chosenPage == Page::STARTGAME &&
		loadedPage != Page::STARTGAME)
	{
		interface.ClearItems();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component(textures, "Gray Area", 4);
				component.setType(Component::Type::TEXT);
				component.setPosition(960, 100);
				component.setTextColorRef(component, 30, 30, 30, 255);
				component.outlineThickness = 0;
				interface.components.push_back(component);
				//title
				component.setTextColorRef(component, 255, 255, 255, 255);
				component.sizeRatio = 2.6;
				interface.components.push_back(component);
			}

			//dont forget the if statement
			/*for (int i = 0; i < worlds.size(); i++)
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
				interface.setRectColor(interface,80,80,80,180);
				interface.position[0] = 960;
				interface.position[1] = 320 + (i * 150);
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}*/

			if (count == 1 && worlds.size() < maxWorlds)
			{
				//New World
				Component component(textures, "Create New World", 1.5);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::NAMEWORLD;
				component.setPosition(960, 320 + (worlds.size() * 150));
				interface.components.push_back(component);
			}

			if (count == 2)
			{
				//BACK
				Component component(textures, "Back", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::STARTPAGE;
				component.setPosition(960, 900);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}