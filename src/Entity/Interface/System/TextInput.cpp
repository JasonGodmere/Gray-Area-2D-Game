
#include "Interface.h"

void Interface::TextInput(Controls& controls)
{
	sf::Rect<float> size = text.getGlobalBounds();
	//sf::Rect<float> size1 = text1.getGlobalBounds();

	controls.typing = true;
	string = controls.playerString;

	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColor[0], textColor[1], textColor[2], textColor[3]));

	//text1.setString(string1);
	//text1.setCharacterSize(characterSize);
	//text1.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));

	rect.setFillColor(sf::Color(rectColor[0], rectColor[1], rectColor[2], rectColor[3]));

	//accept button
	/*if (controls.mousePosX >= posX1 - rect1.getSize().x / 2 &&
		controls.mousePosX <= posX1 + rect1.getSize().x / 2)
	{
		if (controls.mousePosY >= posY1 - rect1.getSize().y / 2 &&
			controls.mousePosY <= posY1 + rect1.getSize().y / 2)
		{
			text1.setCharacterSize(characterSize + 5);

			if (pressed == false && controls->leftClick == true && string != "")
			{
				pressed = true;
			}
		}
	}*/

	text.setOrigin(sf::Vector2f(size.width / 2 + textOriginX, size.height / 2 + 15 + textOriginY));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	//text1.setOrigin(sf::Vector2f(size1.width / 2 + textOriginX, size1.height / 2 + 15 + textOriginY));
	//text1.setPosition(sf::Vector2f(posX1, posY1));

	rect.setPosition(position[0], position[1]);
	//rect1.setPosition(posX1, posY1);
}