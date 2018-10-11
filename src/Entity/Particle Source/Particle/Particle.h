#pragma once

#include "../../Entity.h"

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

	void Update(Physics& physics);
	void Draw(Physics& physics, sf::RenderWindow& window);
};