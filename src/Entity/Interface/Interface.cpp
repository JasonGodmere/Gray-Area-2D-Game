
#include "Interface.h"

void Interface::ClearItems()
{
	systems.clear();
	components.clear();
}

void Interface::Update(Controls& controls, sf::RenderWindow& window)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i].Update(controls, window);
	}

	for (int i = 0; i < systems.size(); i++)
	{
		systems[i].Update(controls, window);
	}
}