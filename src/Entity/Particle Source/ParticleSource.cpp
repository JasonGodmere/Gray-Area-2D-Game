
#include "ParticleSource.h"

ParticleSource::ParticleSource()
{
	/*each particle source goes through 2 phases, the first is after being constructed.
	This first step starts spawning particles until the longest possible duration has happened,
	then it goes to phase 2 for the rest of its life, re-using no longer visible particles*/
	justSpawned = true;
	vectorSize = 0;
	vectorCount = 0;
	
	spawn = 0;
	intSpawn = 0;
	unusedSpawn = 0;
	unusedParticles = 0;
}

ParticleSource::~ParticleSource()
{
	//thingy
}

void ParticleSource::Update(Physics& physics)
{
	if (true)//this should be offloaded to the class using particles and put in as arguments for constructor
	{
		spawnPerSec = .06;
		durationHigh = 6;
		durationLow = 6;
		speedHigh = 150;
		speedLow = 80;
		sizeLow = 10;
		sizeHigh = 30;

		ParticleSource::SpawnSource(physics);
	}
}

void ParticleSource::Draw(Physics& physics, sf::RenderWindow& window)
{
	ParticleSource::Update(physics);

	count = 0;
	for (particlesIter = particles.begin(); particlesIter != particles.end(); particlesIter++)
	{
		particles[count].Draw(physics, window);
		++count;
	}

	window.draw(rect);
}