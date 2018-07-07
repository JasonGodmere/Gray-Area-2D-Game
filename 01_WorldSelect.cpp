
#include "01_Interface.h"

void Interface::WorldSelect(Controls *controls)
{
	sf::Rect<float> size = text.getGlobalBounds();

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, rectColorA));
	rect.setOutlineThickness(0);

	if (controls->mousePosX >= posX - rect.getSize().x / 2 &&
		controls->mousePosX <= posX + rect.getSize().x / 2)
	{
		if (controls->mousePosY >= posY - rect.getSize().y / 2 &&
			controls->mousePosY <= posY + rect.getSize().y / 2)
		{
			rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, 255));
			rect.setOutlineThickness(2);

			if (pressed == false && controls->leftClick == true)
			{
				pressed = true;
			}
		}
	}

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(posX, posY));

	rect.setPosition(posX, posY);
}