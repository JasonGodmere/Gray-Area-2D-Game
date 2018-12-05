
#include "../Menu.h"

void Menu::NameWorld(Textures& textures)
{
	if (chosenPage == Page::NAMEWORLD &&
		loadedPage != Page::NAMEWORLD)
	{
		interface.ClearItems();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component(textures, "Name World", 4);
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
				System system(textures, "Generate World", 15, 500, 80);
				system.components[System::TextInput::TEXT_BOX].setRectColorRef(system.components[System::TextInput::TEXT_BOX],60,60,60);
				system.setPosition(960, 400); 
				interface.systems.push_back(system);
			}

			if (count == 2)
			{
				//CANCEL
				Component component(textures, "Cancel", 1);
				component.setType(Component::Type::SIZE_BUTTON);
				component.buttonIndex = Page::STARTPAGE;
				component.setPosition(960, 900);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}