
#include "Interface.h"

void Interface::WorldSelect(Controls& controls)
{
	sf::Rect<float> size = text.getGlobalBounds();

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, rectColorA));
	rect.setOutlineThickness(0);

	if (controls.mousePosX >= position[0] - rect.getSize().x / 2 &&
		controls.mousePosX <= position[1] + rect.getSize().x / 2)
	{
		if (controls.mousePosY >= position[0] - rect.getSize().y / 2 &&
			controls.mousePosY <= position[1] + rect.getSize().y / 2)
		{
			rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, 255));
			rect.setOutlineThickness(2);

			if (pressed == false && controls.leftClick == true)
			{
				pressed = true;
			}
		}
	}

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	rect.setPosition(position[0], position[1]);
}