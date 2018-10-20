#pragma once

#include "../Physics/Physics.h"
#include "../Controls/Controls.h"

class Entity : public Physics
{
public:
	int spriteFrame;

	bool justSpawned;

	//text
	static const int textSize = 40;
	int rectSize;//the base pixel size of the sprite/shape before ratio

	float sizeRatio;//for in game objects, based on resolution

	int outlineThickness;

	//Trig Variables
	float angle;
	float legX;
	float legY;
	float hyp;

	int count;//get rid of this, it is used messily in particle

	sf::Text text;

	std::string string;

	sf::Sprite sprite;
	sf::RectangleShape rect;
	sf::CircleShape circle;

	virtual void setPosition(float x, float y)
	{
		position[0] = x;
		position[1] = y;
	}
};