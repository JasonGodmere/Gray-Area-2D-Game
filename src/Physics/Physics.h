#pragma once

#include "../Textures/Textures.h"

class Physics
{
private:
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

public:
	//time related functions
	virtual sf::Text getText() { return text; };
	virtual double getTime() { return time; };
	virtual void UpdateClock(Textures& textures);

	const int gravity;

	float lastPosition[2];
	float position[2];//2 axis of position (x,y), index[0] = x, index[1] = y
	float speed;//total units per second
	float rate[2];//directional units per second
	float velocity[2];//directional units per frame
	float acceleration[2];//directional change in units per second
	//see UpdatePhysics() for equation

	const float topSpeed;
	const float fallSpeed;

	Physics();

	virtual void InitPhysics()
	{
		rate[0] = 0;
		rate[1] = 0;
		velocity[0] = 0;
		velocity[1] = 0;
		acceleration[0] = 0;
		acceleration[1] = 0;
	}

	//for entity movement
	virtual void UpdatePhysics(Physics& physics, bool gforce)//this determines if gravity on obj is true
	{
		//refresh the entity's accelerations FIRST then speed and position changes based on collisions AFTER
		//reset lastPosition after collisions

		acceleration[0] = acceleration[0] * physics.time;

		if (gforce == true)
		{
			acceleration[1] = (acceleration[1] + gravity) * physics.time;
		}
		else
		{
			acceleration[1] = acceleration[1] * physics.time;
		}

		rate[0] += acceleration[0];
		rate[1] += acceleration[1];

		//unit per second limiter
		if (rate[0] > topSpeed)
		{
			rate[0] = topSpeed;
		}
		else if (rate[0] < -topSpeed)
		{
			rate[0] = -topSpeed;
		}

		if (rate[1] > fallSpeed)
		{
			rate[1] = fallSpeed;
		}
		else if (rate[1] < -fallSpeed)
		{
			rate[1] = -fallSpeed;
		}

		velocity[0] = rate[0] * physics.time;
		velocity[1] = rate[1] * physics.time;

		position[0] += velocity[0];
		position[1] -= velocity[1];//-= because in sfml, the y axis increases downwards
	};
};
