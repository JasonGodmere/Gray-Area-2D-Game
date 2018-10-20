
#include "System.h"

void System::ButtonArray(Controls& controls, sf::RenderWindow& window)
{
	for (int i = 0; i < components.size(); i++)
	{
		for (int j = 0; j < columns; j++)
		components[i].Update(controls, window);

		text.setPosition(sf::Vector2f(position[0], position[1]));//need to set the positions
		rect.setPosition(position[0], position[1]);//need to set the positions
	}
}