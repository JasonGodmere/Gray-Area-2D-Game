
#include "Interface.h"

void Interface::TextInput(Controls *controls)
{
	sf::Rect<float> size = text.getGlobalBounds();
	sf::Rect<float> size1 = text1.getGlobalBounds();

	controls->typing = true;
	controls->maxChar = maxChar;
	string = controls->playerString;

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	text1.setString(string1);
	text1.setCharacterSize(characterSize);
	text1.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	rect.setFillColor(sf::Color(rectColorR, rectColorG, rectColorB, rectColorA));

	//accept button
	if (controls->mousePosX >= posX1 - rect1.getSize().x / 2 &&
		controls->mousePosX <= posX1 + rect1.getSize().x / 2)
	{
		if (controls->mousePosY >= posY1 - rect1.getSize().y / 2 &&
			controls->mousePosY <= posY1 + rect1.getSize().y / 2)
		{
			text1.setCharacterSize(characterSize + 5);

			if (pressed == false && controls->leftClick == true && string != "")
			{
				pressed = true;
			}
		}
	}

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(posX, posY));

	text1.setOrigin(sf::Vector2f(size1.width / 2 + textOriginX, size1.height / 2 + 15 + textOriginY));
	text1.setPosition(sf::Vector2f(posX1, posY1));

	rect.setPosition(posX, posY);
	rect1.setPosition(posX1, posY1);
}