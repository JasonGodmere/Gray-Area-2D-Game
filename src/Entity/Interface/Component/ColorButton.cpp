 #include "Component.h"

void Component::ColorButton(Controls& controls, sf::RenderWindow& window)
{
	sf::Rect<float> size = text.getGlobalBounds();

	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	rect.setOutlineThickness(0);

	if (controls.mousePosX >= position[0] - rect.getSize().x / 2 &&
		controls.mousePosX <= position[1] + rect.getSize().x / 2)
	{
		if (controls.mousePosY >= position[0] - rect.getSize().y / 2 &&
			controls.mousePosY <= position[1] + rect.getSize().y / 2)
		{
			rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], 255));

			if (pressed == false && controls.leftClick == true)
			{
				pressed = true;
			}
		}
	}

	if (pressed == true)
	{
		rectColorRef[3] = 255;
		rect.setOutlineThickness(2);
	}

	text.setOrigin(sf::Vector2f(size.width / 2, size.height / 2 + 15));
	text.setPosition(sf::Vector2f(position[0], position[1]));

	rect.setPosition(position[0], position[1]);

	window.draw(rect);
	window.draw(text);
}