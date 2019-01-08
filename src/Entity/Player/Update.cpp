
#include "Player.h"

void Player::Update(Physics& physics, Controls& controls, World* world, sf::RenderWindow &window)
{
	Player::Aiming(controls, window);

	if (controls.d == true && controls.a == false)
	{
		//accelerationX = topSpeed * 8;
		rate[0] = topSpeed;
	}
	else if (controls.d == false && controls.a == true)
	{
		//accelerationX = -topSpeed * 8;
		rate[0] = -topSpeed;
	}
	else
	{
		rate[0] = 0;
	}

	Player::Jump(controls);
	
	Player::UpdatePhysics(physics, false);//located in physics

	Player::Running(controls, window);
	Player::Building(controls, world);

	
}
