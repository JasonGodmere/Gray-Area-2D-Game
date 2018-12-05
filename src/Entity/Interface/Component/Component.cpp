
#include "Component.h"

Component::Component(Textures& textures, std::string string, int sizeRatio)
	: rectColorRef({ 60,60,60,255 }), textColorRef({ 255,255,255,255 }),
	pressed(false), type(Type::NONE), border(false)
{
	this->sizeRatio = sizeRatio;

	text.setString(string);
	text.setCharacterSize(textSize * sizeRatio);
	text.setFont(textures.font->sansation);

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
}

Component::Component(Textures& textures, std::string string, int sizeRatio, std::array<int, 2> borderSize)
	: rectColorRef({ 60,60,60,255 }), textColorRef({ 255,255,255,255 }),
	pressed(false), type(Type::NONE), border(true), borderSize({borderSize[0], borderSize[1]})
{
	this->sizeRatio = sizeRatio;

	text.setString(string);
	text.setCharacterSize(textSize * sizeRatio);
	text.setFont(textures.font->sansation);

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));

	rect.setSize(sf::Vector2f(borderSize[0], borderSize[1]));
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
}

void Component::Update(Controls& controls, sf::RenderWindow& window)
{

	if (type == Type::TEXT)
	{
		type = Type::TEXT;
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