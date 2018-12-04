
#include "System.h"

System::System(std::vector<Component> buttons)
	:columns(columns), components(buttons)
{
	type = Type::BUTTON_ARRAY;
	//for ButtonArray

	for (int i = 0; i < components.size(); i++)
	{
		
	}
}

System::System(Textures& textures, std::string buttonName, int maxChar, int borderX, int borderY)
	:maxChar(maxChar)//not being used currently
{
	type = Type::TEXT_INPUT;
	//for TextInput

	Component textBox(textures, "", 1);
	textBox.borderSize[0] = borderX;
	textBox.borderSize[1] = borderY;
	textBox.border = true;//default border for text box
	textBox.rect.setOutlineThickness(3);
	textBox.rect.setOutlineColor(sf::Color::White);
	textBox.setType(Component::Type::TEXT);
	components.push_back(textBox);

	Component acceptButton(textures, buttonName, 3);
	acceptButton.setType(Component::Type::SIZE_BUTTON);
	components.push_back(acceptButton);
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