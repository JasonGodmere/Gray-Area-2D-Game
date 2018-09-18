
#include "03_Player.h"

void Player::PlayerCollision(int x, int y, Physics& physics, std::vector<std::vector<Chunk>> &chunks)
{
	rectLeftEdge = posX - rect.getOrigin().x;
	rectRightEdge = posX + rect.getSize().x - rect.getOrigin().x;
	rectTopEdge = posY - rect.getOrigin().y;
	rectBottomEdge = posY + rect.getSize().y - rect.getOrigin().y;

	leftEdge = posX + chunks[y][x].originX;
	rightEdge = posX + chunks[y][x].chunkSize + chunks[y][x].originX;
	topEdge = posY + chunks[y][x].originY;
	bottomEdge = posY + chunks[y][x].chunkSize + chunks[y][x].originY;

	//bottom
	if (((rectLeftEdge > leftEdge && rectLeftEdge < rightEdge) ||
		(leftEdge > rectLeftEdge && leftEdge < rectRightEdge)) && speedY <= 0)
	{
		if (rectBottomEdge <= topEdge && rectBottomEdge >= topEdge - rectInfluenceMargin && grounded == false)// && bottomCollision == false)
		{
			speedY = 0;
			velocityY = 0;
			posY = chunks[y][x].originY;
			grounded = true;
			//cout << "working" << endl;
		}
	}
}