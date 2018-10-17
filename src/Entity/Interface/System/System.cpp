
#include "System.h"

void System::Update(Controls& controls, sf::RenderWindow& window)
{
	if (type == Type::TEXT_INPUT)
	{
		System::TextInput(controls, window);
	}

	else if (type == Type::BUTTON_ARRAY)
	{
		System::ButtonArray(controls, window);
	}
}