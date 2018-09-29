
#include "03_Player.h"

void Player::PlayerCollision(Physics& physics, std::vector<std::vector<Chunk>>& chunks)
{
	/*rectLeftEdge = posX - rect.getOrigin().x;
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
	}*/
	
	//corners collisions

	//chunk[0 for x, 1 for y][pointNumber]
	chunkCollisionPoints[0][0] = posX - rect.getOrigin().x;//top left
	chunkCollisionPoints[1][0] = posY - rect.getOrigin().y;//top left
	chunkCollisionPoints[0][1] = posX - rect.getOrigin().x + rect.getSize().x;//top right
	chunkCollisionPoints[1][1] = posY - rect.getOrigin().y;//top right
	chunkCollisionPoints[0][2] = posX - rect.getOrigin().x + rect.getSize().x;//bottom right
	chunkCollisionPoints[1][2] = posY - rect.getOrigin().y + rect.getSize().y;//bottom right
	chunkCollisionPoints[0][3] = posX - rect.getOrigin().x;//bottom left
	chunkCollisionPoints[1][3] = posY - rect.getOrigin().y + rect.getSize().y;//bottom left

	//player[0 for x, 1 for y][pointNumber]
	playerCollisionPoints[0][0] = posX - chunk.originX;//top left
	playerCollisionPoints[1][0] = posY - chunk.originY;//top left
	playerCollisionPoints[0][1] = posX - chunk.originX + chunk.chunkSize;//top right
	playerCollisionPoints[1][1] = posY - chunk.originY;//top right
	playerCollisionPoints[0][2] = posX - chunk.originX + chunk.chunkSize;//bottom right
	playerCollisionPoints[1][2] = posY - chunk.originY + chunk.chunkSize;//bottom right
	playerCollisionPoints[0][3] = posX - chunk.originX;//bottom left
	playerCollisionPoints[1][3] = posY - chunk.originY + chunk.chunkSize;//bottom left


	//bottom collision (gets priorty over top collision)
	
	for 

	//after collisions
	lastPosX = posX;
	lastPosY = posY;
}