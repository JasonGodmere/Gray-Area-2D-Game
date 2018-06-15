#include "Particle.h"

void Particle::Menu()
{
	if (timeSinceSpawn >= duration)
	{
		colorA = 0;
	}
	else
	{
		colorR = 50 * (1 - (timeSinceSpawn / duration));
		colorG = 50 * (1 - (timeSinceSpawn / duration));
		colorB = 50 * (1 - (timeSinceSpawn / duration));
	}

	rect.setFillColor(sf::Color(colorR, colorG, colorB, colorA));
}