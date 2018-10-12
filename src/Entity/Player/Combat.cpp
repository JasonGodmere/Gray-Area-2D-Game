
#include "Player.h"

void Player::Aiming(Controls& controls, sf::RenderWindow &window)
{
	//Executing where to face and where to aim

	legX = controls.mousePosX - armT1.getPosition().x;
	legY = controls.mousePosY - armT1.getPosition().y;
	hyp = sqrt(legX*legX + legY * legY);
	angle = (asin(legY / hyp) * 180) / 3.1415;

	if (legX > 0 && legY < 0)
	{
		//Quadrant 1
		angle = angle - 90;
	}
	else if (legX < 0 && legY < 0)
	{
		//Quadrant 2
		angle = 90 - angle;
	}
	else if (legX < 0 && legY > 0)
	{
		//Quadrant 3
		angle = 90 - angle;
	}
	else if (legX > 0 && legY > 0)
	{
		//Quadrant 4
		angle = angle - 90;
	}

	armT2.setRotation(angle);
	armB2.setRotation(angle);

	/*if (facing == LEFT)
	{
		armT1.setRotation(angle - 20);
		armB1.setRotation(angle - 20);
	}
	else if (facing == RIGHT)
	{
		armT1.setRotation(angle + 20);
		armB1.setRotation(angle + 20);
	}*/
}