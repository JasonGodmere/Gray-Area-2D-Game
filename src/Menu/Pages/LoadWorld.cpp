
#include "../Menu.h"

void Menu::LoadWorld(Textures& textures)
{
	if (chosenPage == Interface::Menu::LOADGAME &&
		loadedPage != Interface::Menu::LOADGAME)
	{
		UI.clear();
		elements = 1;
		for (int i = 0; i < elements; i++)
		{
			//INTERFACE
			Interface interface(textures);

			if (i == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "Loading - " + worlds[worldSelected].worldName;
				interface.characterSize = 120;
				interface.position[0] = 960;
				interface.position[1] = 100;
				interface.setTextColor(interface,30,30,30,255);
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.setTextColor(interface,255,255,255,255);
				interface.characterSize = 80;
				UI.push_back(interface);
			}
		}
	}

	//std::thread LoadingThread(LoadingScreen, this);

	//after loading sequence
	chosenPage = Interface::Menu::INGAME;
}