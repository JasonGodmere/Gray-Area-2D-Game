
#include "03_Player.h"

void Player::Update(Physics& physics, Controls *controls, sf::RenderWindow &window)
{
	mousePosX = controls->mousePosX;
	mousePosY = controls->mousePosY;

	Player::Aiming(window);

	time = physics.time;

	//Y axis movement
	if (grounded == false && speedY > (fallSpeed))
	{
		speedY = fallSpeed;
	}
	else if (grounded == false && speedY < -fallSpeed)
	{
		speedY = -fallSpeed;
	}

	if (controls->d == true && controls->a == false)
	{
		//accelerationX = topSpeed * 8;
		speedX = topSpeed;
	}
	else if (controls->d == false && controls->a == true)
	{
		//accelerationX = -topSpeed * 8;
		speedX = -topSpeed;
	}
	else
	{
		speedX = 0;
	}
	
	accelerationX = accelerationX * time;
	accelerationY = (accelerationY + physics.gravity) * time;

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
	posY = posY - velocityY;//sfml has y axis increase top to bottom rather than bottom to top

	Player::Running(*controls, window);
}
