
#include "../Menu.h"

void Menu::GenerateWorld(Textures& textures)
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
			interface.string = "Generating "; //+ worlds[worldNum].worldName;
			interface.characterSize = 120;
			interface.position[0] = 960;
			interface.position[1] = 100;
			interface.textColorR = 30;
			interface.textColorG = 30;
			interface.textColorB = 30;
			interface.outlineThickness = 0;
			UI.push_back(interface);
			interface.textColorR = 255;
			interface.textColorG = 255;
			interface.textColorB = 255;
			interface.characterSize = 80;
			UI.push_back(interface);
		}
	}
}