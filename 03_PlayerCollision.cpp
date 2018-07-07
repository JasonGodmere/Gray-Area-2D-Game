
#include "03_Player.h"

void Player::PlayerCollision(int x, int y, Clock *clock, std::vector<std::vector<ChunkStruct>> &chunkStructs)
{
	rectLeftEdge = posX - rect.getOrigin().x;
	rectRightEdge = posX + rect.getSize().x - rect.getOrigin().x;
	rectTopEdge = posY - rect.getOrigin().y;
	rectBottomEdge = posY + rect.getSize().y - rect.getOrigin().y;

	leftEdge = posX + chunkStructs[y][x].originX;
	rightEdge = posX + chunkStructs[y][x].chunkSize + chunkStructs[y][x].originX;
	topEdge = posY + chunkStructs[y][x].originY;
	bottomEdge = posY + chunkStructs[y][x].chunkSize + chunkStructs[y][x].originY;

	//top
	/*if ((rectLeftEdge > leftEdge && rectLeftEdge < rightEdge) ||
		(leftEdge > rectLeftEdge && leftEdge < rectRightEdge))
	{
		if (rectTopEdge >= bottomEdge && rectTopEdge <= bottomEdge - rectInfluenceMargin)
		{
			if (chunkStructs[y][x].originY + chunkStructs[y][x].chunkSize == -rectTopEdge)
			{
				//moveY = -Y;
			}
			else
			{
				//moveY == rectTopEdge + bottomEdge;
			}
			if (speedY > 0)
			{
				speedY = 0;
				velocityY = 0;
			}
			topCollision = true;
		}
	}

	//left
	if ((rectTopEdge > topEdge && rectTopEdge < bottomEdge) ||
		(topEdge > rectTopEdge && topEdge < rectBottomEdge))
	{
		if (rectLeftEdge >= rightEdge && rectLeftEdge <= rightEdge - rectInfluenceMargin)
		{
			if (chunkStructs[y][x].originX + chunkStructs[y][x].chunkSize == rectLeftEdge)
			{
				//moveX = x - X;
			}
			else
			{
				//moveX = rectLeftEdge - rightEdge;
			}
			if (speedX < 0)
			{
				speedX = 0;
				velocityX = 0;
			}
			leftCollision = true;
		}
	}

	//right
	if ((rectTopEdge > topEdge && rectTopEdge < bottomEdge) ||
		(topEdge > rectTopEdge && topEdge < rectBottomEdge))
	{
		if (rectRightEdge <= leftEdge && rectRightEdge >= leftEdge + rectInfluenceMargin)
		{
			if (chunkStructs[y][x].originX + chunkStructs[y][x].chunkSize == rectLeftEdge)
			{
				//moveX = x - X;
			}
			else
			{
				//moveX = rectLeftEdge - rightEdge;
			}
			if (speedX > 0)
			{
				speedX = 0;
				velocityX = 0;
			}
			rightCollision = true;
		}
	}*/

	//bottom
	if (((rectLeftEdge > leftEdge && rectLeftEdge < rightEdge) ||
		(leftEdge > rectLeftEdge && leftEdge < rectRightEdge)) && speedY <= 0)
	{
		if (rectBottomEdge <= topEdge && rectBottomEdge >= topEdge - rectInfluenceMargin && grounded == false)// && bottomCollision == false)
		{
			speedY = 0;
			velocityY = 0;
			posY = chunkStructs[y][x].originY;
			grounded = true;
			//cout << "working" << endl;
		}
	}

	/*For some reason, the block is constantly being activated and is evident when going from positive to negative speedY while jumping*/
}