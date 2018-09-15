#pragma once

#include "Define.h"
#include "40_Textures.h"

class Clock
{ // in milliseconds
public:
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

	sf::Text text;

	Clock();
	~Clock();
	void Update(Textures& textures);
	void Draw(sf::RenderWindow &window);
};