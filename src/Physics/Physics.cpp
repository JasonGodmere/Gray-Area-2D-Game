
#include "Physics.h"

Physics::Physics()
	: count(0), fps(0), fpsCounter(0), averageFps(0), timeCount(0),
	topSpeed(260), fallSpeed(topSpeed * 4), gravity(fallSpeed * 2/*1560*/)
{
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(200,200,10));
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);
}

void Physics::UpdateClock(Textures& textures)
{
	previousTime = currentTime;
	currentTime = std::chrono::steady_clock::now();
	deltaTime = currentTime - previousTime;

	std::chrono::microseconds mic = std::chrono::duration_cast<std::chrono::microseconds>(deltaTime);

	time = mic.count();
	time = time / 1000000; //this makes it into seconds

	if (time > .2) //5fps
	{
		time = .2;
	}

	fps = 1 / time;

	timeCount = timeCount + time;

	fpsCounter = fpsCounter + fps;

	++count;

	if (timeCount >= 1)
	{
		averageFps = fpsCounter / count;
		count = 0;
		timeCount = 0;
		fpsCounter = 0;
		fpsInt = (int)averageFps;
		text.setFont(textures.font->sansation);
		text.setString("Fps: " + std::to_string((int)averageFps));
	}
}