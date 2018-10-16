
#include "Component.h"

Component::Component(enum Type& type, std::string& string, int& textSize)
	: rectColorRef({ 100,100,100,255 }), textColorRef({ 255,255,255,255 }),
	pressed(false), type(Type::NONE)
{
	text.setString(string);
	text.setCharacterSize(textSize * sizeRatio);

	if (type == Type::COLOR_BUTTON)
	{
		
	}
	else if (type == Type::SIZE_BUTTON)
	{
		rectColorRef = { 0,0,0,0 };
	}
	else if (type == Type::TEXT)
	{
		rectColorRef = { 0,0,0,0 };
	}

	rect.setFillColor(sf::Color(rectColorRef[0], rectColorRef[1], rectColorRef[2], rectColorRef[3]));
	text.setFillColor(sf::Color(textColorRef[0], textColorRef[1], textColorRef[2], textColorRef[3]));
}