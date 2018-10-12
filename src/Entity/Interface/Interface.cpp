
#include "Interface.h"

Interface::Interface(Textures& textures)
{
	recorded = false;
	maxChar = 12;
	rectCustom = false;
	pressed = false;
	rect.setOutlineThickness(0);
	rect.setOutlineColor(sf::Color::White);
	rect.setFillColor(sf::Color(0,0,0,0));
	text.setFont(textures.font->sansation);
	//text1.setFont(textures.font->sansation);
	textColorR = 255;
	textColorG = 255;
	textColorB = 255;
	textColorA = 255;

	textOriginX = 0;
	textOriginY = 0;

	rectColorR = 255;
	rectColorG = 255;
	rectColorB = 255;
	rectColorA = 0;

	typing = false;
}

Interface::~Interface()
{
	//thingy
}

void Interface::Update(Controls& controls)
{
	if (type == Type::TEXT)
	{
		Interface::Text();
	}

	if (buttonType == ButtonType::SIZE && type == Interface::Type::BUTTON)
	{
		Interface::SizeButton(controls);
	}

	if (buttonType == ButtonType::COLOR && type == Interface::Type::BUTTON)
	{
		Interface::ColorButton(controls);
	}

	if (type == Type::TEXTINPUT)
	{
		string = controls.playerString;
		Interface::TextInput(controls);
	}

	if (type == Type::WORLDSELECT)
	{
		Interface::WorldSelect(controls);
	}
}

void Interface::Draw(Controls& controls, sf::RenderWindow& window)
{
	Interface::Update(controls);

	window.draw(rect);
	window.draw(text);
	//window.draw(text1);
}