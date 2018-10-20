
#include "System.h"

void System::TextInput(Controls& controls, sf::RenderWindow& window)
{
	controls.typing = true;
	string = controls.playerString;

	components[0].Update(controls, window);
	components[1].Update(controls, window);

	components[0].setPosition(position[0], position[1] - 100);//textBox
	components[1].setPosition(position[0], position[1] + 10);//acceptButton
}