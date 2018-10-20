
#include "Component.h"

Component::Component(Textures& textures, std::string string, int sizeRatio)
	: rectColorRef({ 100,100,100,255 }), textColorRef({ 255,255,255,255 }),
	pressed(false), type(Type::NONE)
{
	this->sizeRatio = sizeRatio;

	text.setString(string);
	text.setCharacterSize(textSize * sizeRatio);
	text.setFont(textures.font->sansation);

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
}

Component::Component(Textures& textures)
	: rectColorRef({ 100,100,100,255 }), textColorRef({ 255,255,255,255 }),
	pressed(false), type(Type::NONE)
{
	text.setString("default");
	text.setCharacterSize(textSize * 1);

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
}

void Component::Update(Controls& controls, sf::RenderWindow& window)
{

	if (type == Type::TEXT)
	{
		type = Type::TEXT;
		rectColorRef = { 0,0,0,0 };
		Component::Text(window);
	}

	else if (type == Type::COLOR_BUTTON)
	{
		this->type = Type::COLOR_BUTTON;
		Component::ColorButton(controls, window);
	}

	else if (type == Type::SIZE_BUTTON)
	{
		type = Type::SIZE_BUTTON;
		rectColorRef = { 0,0,0,0 };
		Component::SizeButton(controls, window);
	}
}