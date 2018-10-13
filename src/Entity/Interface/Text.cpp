
#include "Interface.h"

void Interface::Text()
{
	text.setString(string);
	text.setCharacterSize(characterSize);
	text.setFillColor(sf::Color(textColor[0], textColor[1], textColor[2], textColor[3]));
	sf::Rect<float> size = text.getGlobalBounds();
	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 10));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	rect.setFillColor(sf::Color(0,0,0,0));
}