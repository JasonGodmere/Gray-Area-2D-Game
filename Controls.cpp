
#include "Controls.h"

Controls::Controls()
{
	typing = false;
	letterPressed = 0;
	leftClickToggle = true;
}

Controls::~Controls()
{
	//thingy
}

void Controls::Update(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		w = true;
	}
	else
	{
		w = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		a = true;
	}
	else
	{
		a = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		s = true;
	}
	else
	{
		s = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		d = true;
	}
	else
	{
		d = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		space = true; //needs toggle implementation
	}
	else
	{
		space = false;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		esc = true; //needs toggle implementation
	}
	else
	{
		esc = false;
	}

	if (typing == false)
	{
		playerString = "";
	}

	letterPressed = 0;
	if (event.type == sf::Event::TextEntered && typing == true) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && playerString.size() > 0) {
			playerString.pop_back();
		}
		else if (event.text.unicode < 128 && playerString.length() < maxChar) {
			letterPressed = (char)event.text.unicode;
			playerString.push_back(letterPressed);
		}
	}
}