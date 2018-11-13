
#include "System.h"

void System::TextInput(Controls& controls, sf::RenderWindow& window)
{
	controls.typing = true;
	string = controls.playerString;

	components[TEXT_BOX].Update(controls, window);
	components[ACCEPT_BUTTON].Update(controls, window);
	
	components[TEXT_BOX].text.setString(controls.playerString);

	if (components[ACCEPT_BUTTON].getPressed() == true)
	{
		controls.typing = false;
		controls.playerString = "";
	}

	components[TEXT_BOX].setPosition(position[0], position[1] - 100);
	components[ACCEPT_BUTTON].setPosition(position[0], position[1] + 100);
}