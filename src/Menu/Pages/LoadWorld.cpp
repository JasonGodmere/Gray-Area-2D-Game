
#include "../Menu.h"

void Menu::LoadWorld(Textures& textures)
{
	if (chosenPage == Page::LOADGAME &&
		loadedPage != Page::LOADGAME)
	{
		interface.components.clear();

		int count = 0;
		do
		{
			if (count == 0)
			{
				//title - shadow
				Component component("Gray Area", 3);
				component.type = Component::Type::TEXT;
				component.setPosition(960, 100);
				component.setTextColorRef(component, 30, 30, 30, 255);
				component.outlineThickness = 0;
				interface.components.push_back(component);
				//title
				component.setTextColorRef(component, 255, 255, 255, 255);
				component.sizeRatio = 2;
				interface.components.push_back(component);
			}

			count++;

		} while (count <= interface.components.size());
	}

	//std::thread LoadingThread(LoadingScreen, this);

	//after loading sequence
	chosenPage = Page::INGAME;
}