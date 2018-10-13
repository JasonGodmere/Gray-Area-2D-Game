
#include "../Menu.h"

void Menu::Achievements(Textures& textures)
{
	if (chosenPage == Interface::Menu::ACHIEVEMENTS &&
		loadedPage != Interface::Menu::ACHIEVEMENTS)
	{
		UI.clear();
		elements = 2;
		for (int i = 0; i < elements; i++)
		{
			//INTERFACE
			Interface interface(textures);

			if (i == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "ACHIEVEMENTS";
				interface.characterSize = 120;
				interface.setPosition(960,100);
				interface.setTextColor(interface,30,30,30,255);
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.setRectColor(interface,255,255,255,255);
				interface.characterSize = 80;
				UI.push_back(interface);
			}

			if (i == 1)
			{
				//BACK
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::STARTPAGE;
				interface.string = "Back";
				interface.characterSize = 50;
				interface.position[0] = 960;
				interface.position[1] = 900;
				interface.outlineThickness = 0;
				UI.push_back(interface);
			}
		}
	}
}