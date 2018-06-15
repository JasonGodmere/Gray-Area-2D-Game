#pragma once

/*#include "Projectile.h"
#include "Enemy.h"*/
#include "Interface.h"
#include "ParticleSource.h"

class Arrays
{
public:
	std::vector<Interface> UI;
	std::vector<Interface>::iterator UIIter;

	std::vector<ParticleSource> particleSources;
	std::vector<ParticleSource>::iterator particleSourcesIter;

	//std::vector<World> worlds;
	//std::vector<World>::iterator worldsIter;

	//std::vector<Enemy> enemies;
	//std::vector<Enemy>::iterator enemiesIter;
};