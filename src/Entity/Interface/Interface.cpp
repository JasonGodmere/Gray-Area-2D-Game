
#include "Interface.h"

Interface::Interface()
{
	
}

void Interface::Update(Controls& controls, sf::RenderWindow& window)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i].Update(controls, window);
	}
}