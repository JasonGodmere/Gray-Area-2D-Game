
#include "System.h"

System::System(std::vector<Component> buttons, int columns)
	:columns(columns), components(buttons)
{
	type = Type::BUTTON_ARRAY;
	//for ButtonArray

	for (int i = 0; i < components.size(); i++)
	{
		
	}
}

System::System(Textures& textures, std::string buttonName, int maxChar)
	:maxChar(maxChar)
{
	type = Type::TEXT_INPUT;
	//for TextInput

	Component textBox(textures);
	textBox.type = Component::Type::TEXT;
	components.push_back(textBox);

	Component acceptButton(textures);
	acceptButton.type = Component::Type::SIZE_BUTTON;
	acceptButton.string = buttonName;
}

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