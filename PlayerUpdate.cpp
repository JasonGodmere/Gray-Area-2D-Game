
#include "Player.h"

void Player::Update(Clock *clock, Controls *controls, sf::RenderWindow &window)
{
	mousePosX = controls->mousePosX;
	mousePosY = controls->mousePosY;

	Player::Aiming(window);

	time = clock->time;

	gravity = -1560;

	//Y axis movement
	if (grounded == false && speedY > (topSpeed * 2.5))
	{
		speedY = topSpeed * 2.5;
	}
	else if (grounded == false && speedY < -(topSpeed * 2.5))
	{
		speedY = -topSpeed * 2.5;
	}

	if (controls->d == true && controls->a == false)
	{
		//accelerationX = topSpeed * 8;
		speedX = topSpeed;
	}
	else if (controls->a == true)
	{
		//accelerationX = -topSpeed * 8;
		speedX = -topSpeed;
	}
	else
	{
		if (speedX > 1)
		{
			accelerationX = -topSpeed * 8;
			if (speedX + accelerationX < 1)
			{
				accelerationX = 0;
			}
		}
		else if (speedX < -1)
		{
			accelerationX = topSpeed * 8;
			if (speedX + accelerationX > -1)
			{
				accelerationX = 0;
			}
		}
		else
		{
			speedX = 0;
			accelerationX = 0;
		}
		speedX = 0;
	}
	
	accelerationX = accelerationX * time;
	accelerationY = (accelerationY + gravity) * time;

	speedX = speedX + accelerationX;
	speedY = speedY + accelerationY;

	if (grounded == true && speedY < 0)
	{
		speedY = 0;
	}

	Player::Jump(controls);

					 //X axis movement
	if (speedX > topSpeed)
	{
		speedX = topSpeed;
	}
	else if (speedX < -topSpeed)
	{
		speedX = -topSpeed;
	}

	//x-axis
	if (time == 0)
	{
		velocityX = 0;
		velocityY = 0;
	}
	else
	{
		velocityX = speedX * time;
		velocityY = speedY * time;
	}
	
	posX = posX + velocityX;
	posY = posY - velocityY;

	//temporary collision simulation
	/*if (posY >= 0 && controls->space == false)
	{
		speedY = 0;
		velocityY = 0;
		posY = 0;
		grounded = true;
		canJump = true;
	}
	else
	{
		canJump = false;
		grounded = false;
	}*/

	//for platforms

	Player::Running(window);
	Player::Idle();
}
