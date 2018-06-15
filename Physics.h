#pragma once

#include "Clock.h"

class Physics : public Clock
{
public:
	double speed;
	int gravity = -1560;
	double speedX;
	double speedY;
	double velocityX;
	double velocityY;
	double accelerationX;
	double accelTimeX;
	double accelerationY;
	double accelTimeY;
};
