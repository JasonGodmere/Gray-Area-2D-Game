#include "Interface.h"

void Interface::SizeButton(Controls *controls)
{
	sf::Rect<float> size = text.getGlobalBounds();

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, rectColorA));

	if (controls->mousePosX >= posX - rect.getSize().x / 2 &&
		controls->mousePosX <= posX + rect.getSize().x / 2)
	{
		if (controls->mousePosY >= posY - rect.getSize().y / 2 &&
			controls->mousePosY <= posY + rect.getSize().y / 2)
		{
			text.setCharacterSize(characterSize + 5);

			if (controls->leftClick == true)
			{
				pressed = true;
			}
		}
	}

	rect.setSize(sf::Vector2f(size.width, size.height));
	rect.setOrigin(size.width / 2, size.height / 2);

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(posX, posY));

	rect.setPosition(posX, posY);
}