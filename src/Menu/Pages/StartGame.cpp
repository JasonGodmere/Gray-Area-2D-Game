
#include "../Menu.h"

void Menu::StartGame(Textures& textures)
{
	if (worlds.size() == NULL && loadedPage != Page::NAMEWORLD)
	{
		chosenPage = Page::NAMEWORLD;
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

			if (count == 1)
			{
				for (int i = 0; i < worlds.size(); i++)
				{
					//world buttons
					Component component(textures, worlds[i].worldName, 1.5);
					component.setType(Component::Type::SIZE_BUTTON);
					component.buttonIndex = Page::LOADGAME;
					component.setPosition(960, 320 + (i * 150));
					interface.components.push_back(component);
				}
			}

			if (count == 2 && worlds.size() < maxWorlds)
			{
				//New World
				Component component(textures, "Create New World", 1.5);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::NAMEWORLD;
				component.setPosition(960, 320 + (worlds.size() * 150));
				interface.components.push_back(component);
			}

			if (count == 3)
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