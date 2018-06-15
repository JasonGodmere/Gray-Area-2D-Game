
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

void ParticleSource::Update(Clock *clock)
{
	time = clock->time;

	if (type == FIRE)
	{
		spawnPerSec = .06;
		durationHigh = 6;
		durationLow = 6;
		speedHigh = 150;
		speedLow = 80;
		sizeLow = 10;
		sizeHigh = 30;

		ParticleSource::FireSource();
	}
}

void ParticleSource::Draw(Clock *clock, sf::RenderWindow& window)
{
	ParticleSource::Update(clock);

	count = 0;
	for (particlesIter = particles.begin(); particlesIter != particles.end(); particlesIter++)
	{
		particles[count].Draw(clock, window);
		++count;
	}

	window.draw(rect);
}