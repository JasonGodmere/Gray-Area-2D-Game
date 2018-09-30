
#include "03_Player.h"

void Player::PlayerCollision(Physics& physics, std::vector<std::vector<Chunk>>& chunks, int width, int height)
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

	//player[0 for x, 1 for y][pointNumber]
	/*
	chunkCollisionPoints[0][0] = posX + chunks[y][x].originX;//top left
	chunkCollisionPoints[1][0] = posY + chunks[y][x].originY;//top left
	chunkCollisionPoints[0][1] = posX + chunks[y][x].originX + chunks[y][x].chunkSize;//top right
	chunkCollisionPoints[1][1] = posY + chunks[y][x].originY;//top right
	chunkCollisionPoints[0][2] = posX + chunks[y][x].originX + chunks[y][x].chunkSize;//bottom right
	chunkCollisionPoints[1][2] = posY + chunks[y][x].originY + chunks[y][x].chunkSize;//bottom right
	chunkCollisionPoints[0][3] = posX + chunks[y][x].originX;//bottom left
	chunkCollisionPoints[1][3] = posY + chunks[y][x].originY + chunks[y][x].chunkSize;//bottom left
	*/

	//blocks within player movement area between frames are calculated
	if (velocityY >= 0) //leading edge is bottom
	{
		collisionZoneY[0] = height / 4 - (int)(lastPosY / chunks[0][0].chunkSize/*doesn't matter which chunk, all the same size*/);
		collisionZoneY[1] = height / 4 - (int)(posY / chunks[0][0].chunkSize) + 1;//+ 1 to include chunks partially in the high part of range
	}
	else if (velocityY < 0)//leading edge is top (for y)
	{
		collisionZoneY[0] = height / 4 - (int)(posY / chunks[0][0].chunkSize);
		collisionZoneY[1] = height / 4 - (int)(lastPosY / chunks[0][0].chunkSize) + 1;
	}

	if (velocityX >= 0)//leading edge is right
	{
		collisionZoneX[0] = width / 2 - (int)((-lastPosX + playerCollisionPoints[0][2]) / chunks[0][0].chunkSize);
		collisionZoneX[1] = width / 2 - (int)((-posX - playerCollisionPoints[0][3]) / chunks[0][0].chunkSize) + 1;
	}
	else if (velocityX < 0)//leading edge if left
	{
		collisionZoneX[0] = width / 2 - (int)((-posX + playerCollisionPoints[0][2]) / chunks[0][0].chunkSize);
		collisionZoneX[1] = width / 2 - (int)((-lastPosX - playerCollisionPoints[0][3]) / chunks[0][0].chunkSize) + 1;
	}

	//std::cout << collisionZoneX[0] << " : " << collisionZoneX[1] << std::endl;
	//std::cout << collisionZoneY[0] << " : " << collisionZoneY[1] << std::endl;
	//std::cout << "------------------------------------------------------" << std::endl;

	//calculate if there is a block in path starting from lasPos and moving towards pos 
	count = 0;
	for (int y = collisionZoneY[0]; y < collisionZoneY[1]; y++)
	{
		for (int x = collisionZoneX[0]; x < collisionZoneX[1]; x++)
		{
			if (chunks[y][x].collision == true)
			{
				posY = -chunks[y][x].originY;
				grounded == true;
			}
		}
	}

	//after collisions
	lastPosX = posX;
	lastPosY = posY;
}