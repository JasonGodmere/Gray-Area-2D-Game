
#include "Interface.h"

void Interface::Text()
{
	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColorR, textColorG, textColorB, textColorA));
	sf::Rect<float> size = text.getGlobalBounds();
	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 10));
	text.setPosition(sf::Vector2f(posX, posY));

	rect.setFillColor(sf::Color(0,0,0,0));
}