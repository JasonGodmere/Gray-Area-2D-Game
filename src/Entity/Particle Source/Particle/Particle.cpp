
#include "Particle.h"

Particle::Particle()
{
	justSpawned == true;
	timeSinceSpawn = 0;

	rect.setFillColor(sf::Color::White);
}

Particle::~Particle()
{
	//thingy
}

void Particle::Update(Physics& physics)
{
	time = physics.time;

	if (type = FIRE)
	{
		Particle::Menu();
	}

	timeSinceSpawn = timeSinceSpawn + time;

	if (timeSinceSpawn >= duration)
	{
		colorA = 0;
		speedX = 0;
		speedY = 0;
	}

	rect.setSize(sf::Vector2f(rectSize, rectSize));
	circle.setOrigin(rectSize / 2, rectSize / 2);

	velocityX = speedX * time;
	velocityY = speedY * time;
	posX = posX + velocityX;
	posY = posY + velocityY;
	rect.setPosition(posX, posY);
}

void Particle::Draw(Physics& physics, sf::RenderWindow& window)
{
	Particle::Update(physics);

	window.draw(rect);
	//window->draw(circle);
}