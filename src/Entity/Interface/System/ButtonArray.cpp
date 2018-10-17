
#include "System.h"

void System::ButtonArray(Controls& controls, sf::RenderWindow& window)
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i].Update(controls, window);

		text.setPosition(sf::Vector2f(, ));//need to set the positions
		rect.setPosition(, );//need to set the positions
	}
}