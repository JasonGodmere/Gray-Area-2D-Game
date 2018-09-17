#pragma once

#include "02_Particle.h"

class ParticleSource : public Entity
{
public:
	//particle vector size
	int vectorSize;
	int vectorCount;

	//source
	int speedHigh;
	int speedLow;
	int durationHigh;
	int durationLow;
	int sizeLow;
	int sizeHigh;

	int unusedParticles;
	double unusedSpawn;

	int intSpawn;
	double spawn;
	int spawnWidth;
	double spawnPerSec;
	double spawnRemainder;

	enum Type { CUSTOM, FIRE };
	Type type;

	std::vector<Particle> particles;
	std::vector<Particle>::iterator particlesIter;

	ParticleSource();
	~ParticleSource();

	//types
	void FireSource();

	void Update(Physics& physics);
	void Draw(Physics& physics, sf::RenderWindow& window);
};