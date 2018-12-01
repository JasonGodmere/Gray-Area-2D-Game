
#include "../Menu.h"

void Menu::StartPage(Textures& textures)
{
	if (chosenPage == Page::STARTPAGE && 
		loadedPage != Page::STARTPAGE)
	{
		//INTERFACE - component array reset
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
				//START GAME
				Component component(textures, "Start Game", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::STARTGAME;
				component.setPosition(960, 300);
				interface.components.push_back(component);
			}

			if (count == 2)
			{
				//ACHIEVEMENTS
				Component component(textures, "Achievements", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::ACHIEVEMENTS;
				component.setPosition(960, 400);
				interface.components.push_back(component);
			}

			if (count == 3)
			{
				//SETTINGS
				Component component(textures, "Settings", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::SETTINGS;
				component.setPosition(960, 500);
				interface.components.push_back(component);
			}

			if (count == 4)
			{
				//EXIT
				Component component(textures, "Exit", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::EXIT;
				component.setPosition(960, 600);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}