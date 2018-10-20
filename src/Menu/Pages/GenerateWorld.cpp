
#include "../Menu.h"

void Menu::GenerateWorld(Textures& textures)
{
	interface.components.clear();

	int count = 0;
	do
	{
		if (count == 0)
		{
			//title - shadow
			Component component("Generating World", 3);
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