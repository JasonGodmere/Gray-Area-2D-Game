
#include "Component.h"

void Component::Text(sf::RenderWindow& window)
{
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
	sf::Rect<float> size = text.getGlobalBounds();
	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 10));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	text.setCharacterSize(textSize * sizeRatio);

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	rect.setSize(sf::Vector2f(borderSize[0], borderSize[1]));
	rect.setOrigin(sf::Vector2f(borderSize[0] / 2, borderSize[1] / 2));
	rect.setPosition(sf::Vector2f(position[0], position[1]));


	if (border == true)
	{
		window.draw(rect);
	}
	window.draw(text);
}