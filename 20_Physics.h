#pragma once

#include "40_Textures.h"

class Physics
{
public:
	Physics();

	void Update(Textures& textures);
	void Draw(sf::RenderWindow& window);

	double speed;
	const int gravity;
	double speedX, speedY;
	double velocityX, velocityY;
	double accelerationX, accelerationY;

	//clock variables
	std::chrono::steady_clock::time_point currentTime;
	std::chrono::steady_clock::time_point previousTime;
	std::chrono::steady_clock::duration deltaTime;

	int fpsInt;
	double time;
	int count;
	double timeCount;
	double fps;
	double fpsCounter;
	double averageFps;

	//for displaying the fps
	sf::Text text;
};
