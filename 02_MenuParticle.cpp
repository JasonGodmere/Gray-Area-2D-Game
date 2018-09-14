#include "02_Particle.h"

void Particle::Menu()
{
	if (timeSinceSpawn >= duration)
	{
		colorA = 0;
	}
	else
	{
		colorR = 60 * (1 - (timeSinceSpawn / duration));
		colorG = 60 * (1 - (timeSinceSpawn / duration));
		colorB = 60 * (1 - (timeSinceSpawn / duration));
	}

	rect.setFillColor(sf::Color(colorR, colorG, colorB, colorA));
}