
#include "../Menu.h"

void Menu::Achievements(Textures& textures)
{
	if (chosenPage == Page::ACHIEVEMENTS &&
		loadedPage != Page::ACHIEVEMENTS)
	{
		interface.ClearItems();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component(textures, "Achievements", 4);
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

			if (count == 1)
			{
				//BACK
				Component component(textures, "Back", 1);
				component.type = Component::Type::SIZE_BUTTON;
				component.buttonIndex = Page::STARTPAGE;
				component.setPosition(960, 900);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}