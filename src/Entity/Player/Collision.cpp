
#include "Player.h"

void Player::Collision(Physics& physics, World* world)
{
	//corners collisions

	//chunk[0 for x, 1 for y][pointNumber]
	playerCollisionPoints[0][0] = rect.getOrigin().x;//top left
	playerCollisionPoints[1][0] = rect.getOrigin().y;//top left
	playerCollisionPoints[0][1] = rect.getOrigin().x + rect.getSize().x;//top right
	playerCollisionPoints[1][1] = rect.getOrigin().y;//top right
	playerCollisionPoints[0][2] = rect.getOrigin().x + rect.getSize().x;//bottom right
	playerCollisionPoints[1][2] = rect.getOrigin().y + rect.getSize().y;//bottom right
	playerCollisionPoints[0][3] = rect.getOrigin().x;//bottom left
	playerCollisionPoints[1][3] = rect.getOrigin().y + rect.getSize().y;//bottom left

	//blocks within player movement area between frames are calculated
	if (velocity[1] >= 0) //leading edge is bottom
	{
		collisionZoneY[0] = world->getSizeY() / 4 - (int)(lastPosY / 32/*world.chunks[0][0].chunkSize/*doesn't matter which chunk, all the same size*/);
		collisionZoneY[1] = world->getSizeY() / 4 - (int)(position[1] / 32 + 1);//+ 1 to include chunks partially in the high part of range
	}
	else if (velocity[1] < 0)//leading edge is top (for y)
	{
		collisionZoneY[0] = world->getSizeY() / 4 - (int)(position[1] / 32);
		collisionZoneY[1] = world->getSizeY() / 4 - (int)(lastPosY / 32) + 1;
	}

	if (velocity[0] >= 0)//leading edge is right
	{
		collisionZoneX[0] = world->getSizeX() / 2 - (int)((-lastPosX + playerCollisionPoints[0][2]) / 32);
		collisionZoneX[1] = world->getSizeX() / 2 - (int)((-position[0] - playerCollisionPoints[0][3]) / 32) + 1;
	}
	else if (velocity[0] < 0)//leading edge if left
	{
		collisionZoneX[0] = world->getSizeX() / 2 - (int)((-position[0] + playerCollisionPoints[0][2]) / 32);
		collisionZoneX[1] = world->getSizeX() / 2 - (int)((-lastPosX - playerCollisionPoints[0][3]) / 32) + 1;
	}

	//std::cout << collisionZoneX[0] << " : " << collisionZoneX[1] << std::endl;
	//std::cout << collisionZoneY[0] << " : " << collisionZoneY[1] << std::endl;
	//std::cout << "------------------------------------------------------" << std::endl;

	//vertical collisions
	if (rate[1] <= 0)//leading edge is bottom
	{
		for (int y = collisionZoneY[0]; y < collisionZoneY[1]; y++)
		{
			for (int x = collisionZoneX[0]; x < collisionZoneX[1]; x++)
			{
				if (world->chunks[y][x].collision == true)
				{
					position[1] = -world->chunks[y][x].originY;
				}
			}
		}
	}
	else if (rate[1] > 0)//leading edge is top
	{
		for (int y = collisionZoneY[1]; y > collisionZoneY[0]; y--)
		{
			for (int x = collisionZoneX[0]; x < collisionZoneX[1]; x++)
			{
				if (world->chunks[y][x].collision == true)
				{
					position[1] = -world->chunks[y][x].originY + rect.getSize().y;
				}
			}
		}
	}

	//horizontal collisions
	/*if (speedX > 0)//leading edge is right
	{
		for (int x = collisionZoneX[0]; x < collisionZoneX[1]; x++)
		{
			for (int y = collisionZoneY[0]; y < collisionZoneY[1]; y++)
			{
				if (chunks[y][x].collision == true)
				{
					posX = -chunks[y][x].originX - rect.getOrigin().x;
				}
			}
		}
	}
	else if (speedX < 0)//leading edge is left
	{
		for (int x = collisionZoneX[0]; x > collisionZoneX[0]; x--)
		{
			for (int y = collisionZoneY[0]; y < collisionZoneY[1]; y++)
			{
				if (chunks[y][x].collision == true)
				{
					posX = -chunks[y][x].originX + chunks[y][x].chunkSize - rect.getOrigin().x;
				}
			}
		}
	}*/

	//after collisions
	lastPosX = position[0];
	lastPosY = position[1];
}