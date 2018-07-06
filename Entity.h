#pragma once

#include "Physics.h"
#include "Controls.h"

class Entity : public Controls
{
public:
	int spriteFrame;

	float sizeRatio;

	int gridX;
	int gridY;

	int originX;
	int originY;

	//rect var
	int rectSize;

	bool justSpawned;

	//text
	int characterSize;
	int outlineThickness;

	int width;
	int height;

	int fullHealth;
	int health;
	bool respawn;

	double sum;
	double topSpeed;
	double fallSpeed;

	double posX;
	double posY;
	double posX1;
	double posY1;
	double posX2;
	double posY2;

	double ratioX;
	double ratioY;

	//Trig Variables
	double angle;
	double legX;
	double legY;
	double hyp;

	bool grounded;
	bool canJump;

	int damage;
	bool dead;

	sf::Text text;
	sf::Text text1;

	std::string string;
	std::string string1;

	enum controls { NONE, LEFTCLICK, RIGHTCLICK, LEFT, RIGHT, JUMP };

	//virtual void Draw(Clock *clock, sf::RenderWindow *window) = 0;

	sf::Sprite sprite;
	sf::RectangleShape rect;
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::CircleShape circle;
	sf::RectangleShape healthRed;
	sf::RectangleShape healthGreen;
};