
#include "../Menu.h"

void Menu::InGame(Physics& physics, Controls& controls, Chunk *chunk, sf::RenderWindow& window, 
	Player *player, Textures& textures)
{
	if (chosenPage == Page::INGAME &&
		loadedPage != Page::INGAME)
	{
		interface.components.clear();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component(textures, "In World - " /*+ worldName*/, 4);
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
				component.setPosition(1400, 200);
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}
}