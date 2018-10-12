
#include "Player.h"

void Player::Running(Controls& controls, sf::RenderWindow &window)
{
	/*if ((grounded == true || canJump == true) && speedX != 0)
	{
		footSpeed = speedX;
		torsoHeight = -pow(footPos / 18, 2) + 70;
	}
	else
	{
		//torsoHeight = baseTorsoHeight;
		footSpeed = speedX / 4;
	}

	if (time == 0)
	{
		footVelocity = 0;
	}
	else
	{
		footVelocity = footSpeed * time;
	}

	//foot step oscilation 
	if (speedX < 0 && legToggle == 0)
	{
		if (footPos <= -50)
		{
			legToggle = 1;
		}
		footPos = footPos + footVelocity;
	}

	if (speedX < 0 && legToggle == 1)
	{
		if (footPos >= 50)
		{
			legToggle = 0;
		}
		footPos = footPos - footVelocity;
	}

	if (speedX > 0 && legToggle == 0)
	{
		if (footPos <= -50)
		{
			legToggle = 1;
		}
		footPos = footPos - footVelocity;
	}

	if (speedX > 0 && legToggle == 1)
	{
		if (footPos >= 50)
		{
			legToggle = 0;
		}
		footPos = footPos + footVelocity;
	}

	// from here, calculates angle of legs
	footHyp = sqrt(pow(torsoHeight, 2) + pow(footPos, 2));
	angleA = acos((torsoHeight) / footHyp) * 180 / 3.1415;
	angle2 = (pow(legLength / 2, 2) + pow(legLength / 2, 2) - pow(footHyp, 2)) / (2 * (legLength / 2)*(legLength / 2)); //a^2 + b^2 - c^2 / 2ab, sss triangle equation
	angle2 = acos(angle2) * 180 / 3.1415;
	angleC = (180 - angle2) / 2;
	angle1 = 180 - (angleA + angleC);


	if (footPos >= 0)
	{
		legT1.setRotation((180 - angle1) * -1);// left, only for pos
		legT2.setRotation(legT1.getRotation() - ((180 - angle2) * -1));
	}
	else
	{
		angle1 = 180 - angleA + angleC;
		legT1.setRotation(180 - angle1);// left, only for pos
		legT2.setRotation(legT1.getRotation() + (180 - angle2));
	}

	footHyp = sqrt(pow(torsoHeight, 2) + pow(footPos, 2));
	angleA = acos((torsoHeight) / footHyp) * 180 / 3.1415;
	angle2 = (pow(legLength / 2, 2) + pow(legLength / 2, 2) - pow(footHyp, 2)) / (2 * (legLength / 2)*(legLength / 2)); //a^2 + b^2 - c^2 / 2ab, sss triangle equation
	angle2 = acos(angle2) * 180 / 3.1415;
	angleC = (180 - angle2) / 2;
	angle1 = 180 - (angleA + angleC);

	if (footPos <= 0)
	{
		legB1.setRotation((180 - angle1) * -1);// left, only for pos
		legB2.setRotation(legB1.getRotation() - ((180 - angle2) * -1));
	}
	else
	{
		angle1 = 180 - angleA + angleC;
		legB1.setRotation(180 - angle1);// left, only for pos
		legB2.setRotation(legB1.getRotation() + (180 - angle2));
	}

	//torso angle
	torso.setRotation(15);
	if (controls.d == true && facing == RIGHT)
	{
		torso.setRotation(20);
	}
	else if (controls.d == false && facing == RIGHT)
	{
		torso.setRotation(10);
	}

	if (controls.a == false && facing == LEFT)
	{
		torso.setRotation(10);
	}
	else if (controls.a == true && facing == LEFT)
	{
		torso.setRotation(20);
	}

	//Determining what direction to face and where the player will aim
	if (mousePosX < playerX)
	{
		facing = LEFT;

		legB1.setRotation(legB1.getRotation() * -1);
		legB2.setRotation(legB2.getRotation() * -1);

		legT1.setRotation(legT1.getRotation() * -1);
		legT2.setRotation(legT2.getRotation() * -1);

		torso.setRotation(torso.getRotation() * -1);
	}

	if (mousePosX > playerX)
	{
		facing = RIGHT;
	}*/
}

void Player::Jump(Controls& controls)
{
	/*if (controls.space == true && grounded == true)
	{
		speedY = fallSpeed;
		grounded = false;
	}*/
}