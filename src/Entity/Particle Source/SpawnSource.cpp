
#include "ParticleSource.h"

void ParticleSource::SpawnSource(Physics& physics)
{
	Particle particle;
	
	if (justSpawned == true) //loop creates all needed particles
	{
		rect.setSize(sf::Vector2f(spawnWidth, 5));
		rect.setOrigin(spawnWidth/2,0);
		rect.setFillColor(sf::Color::White);
		rect.setPosition(position[0], position[1]);

		vectorSize = durationHigh * spawnWidth * spawnPerSec;
		for (int i = 0; i < vectorSize; i++)
		{
			particle.type = Particle::Type::FIRE;
			particles.push_back(particle);
		}
		justSpawned = false;
	}

	spawn = spawnPerSec * spawnWidth * physics.getTime() + unusedSpawn; //how many spawns per loop of proccess, remainder is executed
	unusedSpawn = spawn - (int)spawn;

	while (spawn >= 1)
	{
		particles[vectorCount].rectSize = (rand() % (sizeHigh - sizeLow + 1)) + sizeLow;
		particles[vectorCount].colorA = 255;
		particles[vectorCount].timeSinceSpawn = 0;
		particles[vectorCount].position[0] = position[0] - (spawnWidth / 2) + (rand() % spawnWidth);
		particles[vectorCount].position[1] = position[1];
		particles[vectorCount].duration = (rand() % (durationHigh - durationLow + 1)) + durationLow;
		particles[vectorCount].rate[0] = 0;
		particles[vectorCount].rate[1] = -((rand() % (speedHigh - speedLow + 1)) + speedLow);

		++vectorCount;
			
		if (vectorCount >= vectorSize)
		{
			vectorCount = 0;
		}
		--spawn;
	}
}