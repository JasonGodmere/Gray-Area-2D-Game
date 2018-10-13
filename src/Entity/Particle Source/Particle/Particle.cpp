
#include "Particle.h"

Particle::Particle()
{
	justSpawned == true;
	timeSinceSpawn = 0;

	//particle might not use acceleration so needs to be initialized here
	acceleration[0] = 0;
	acceleration[1] = 0;

	rect.setFillColor(sf::Color::White);
}

Particle::~Particle()
{
	//thingy
}

void Particle::Update(Physics& physics)
{
	if (type = FIRE)
	{
		Particle::Menu();
	}

	timeSinceSpawn = timeSinceSpawn + physics.getTime();

	if (timeSinceSpawn >= duration)
	{
		colorA = 0;
		rate[0] = 0;
		rate[1] = 0;
	}

	rect.setSize(sf::Vector2f(rectSize, rectSize));
	circle.setOrigin(rectSize / 2, rectSize / 2);

	Particle::UpdatePhysics(physics, false);

	rect.setPosition(position[0], position[1]);
}

void Particle::Draw(Physics& physics, sf::RenderWindow& window)
{
	Particle::Update(physics);

	window.draw(rect);
	//window->draw(circle);
}