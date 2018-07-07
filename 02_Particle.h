#pragma once

#include "00_Entity.h"

class Particle : public Entity
{
public:
	//attributes
	double timeSinceSpawn;
	int duration;

	int colorR;
	int colorG;
	int colorB;
	int colorA;

	int distance;

	enum Type { CUSTOM, FIRE };
	Type type;

	Particle();
	~Particle();

	//types
	void Menu();

	void Update(Clock *clock);
	void Draw(Clock *clock, sf::RenderWindow& window);
};