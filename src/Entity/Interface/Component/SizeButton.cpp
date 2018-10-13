
#include "Component.h"

void Component::SizeButton(Controls& controls)
{
	sf::Rect<float> size = text.getGlobalBounds();

	rectColorRef = {0,0,0,0};

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));

	if (controls.mousePosX >= position[0] - rect.getSize().x / 2 &&
		controls.mousePosX <= position[0] + rect.getSize().x / 2)
	{
		if (controls.mousePosY >= position[1] - rect.getSize().y / 2 &&
			controls.mousePosY <= position[1] + rect.getSize().y / 2)
		{
			text.setCharacterSize(characterSize + 5);

			if (controls.leftClick == true)
			{
				pressed = true;
			}
		}
	}

	rect.setSize(sf::Vector2f(size.width, size.height));
	rect.setOrigin(size.width / 2, size.height / 2);

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	rect.setPosition(position[0], position[1]);
}