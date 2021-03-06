
#include "Component.h"

void Component::SizeButton(Controls& controls, sf::RenderWindow& window)
{
	//Even though we dont display rect, we still need it for interaction

	sf::Rect<float> size = text.getGlobalBounds();

	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
	text.setCharacterSize(textSize);

	if (controls.mousePosX >= position[0] - rect.getSize().x / 2 &&
		controls.mousePosX <= position[0] + rect.getSize().x / 2 && 
		controls.mousePosY >= position[1] - rect.getSize().y / 2 &&
		controls.mousePosY <= position[1] + rect.getSize().y / 2)
	{
		text.setCharacterSize(textSize + 5);

		if (controls.leftClick == true)
		{
			pressed = true;
		}
	}

	rect.setSize(sf::Vector2f(size.width, size.height));
	rect.setOrigin(size.width / 2, size.height / 2);

	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 15));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	rect.setPosition(position[0], position[1]);

	window.draw(text);
}