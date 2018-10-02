
#include "31_Chunk.h"

Chunk::Chunk()
{
	spriteFrame = 0;
}

void Chunk::Update()
{
	
	/*topBlock = false;
	bottomBlock = false;
	leftBlock = false;
	rightBlock = false;

	if (y + 1 >= height)
	{
		topBlock = true;
	}
	else if (chunkStructs[y+1][x].front == )*/

	if (originY == 0)
	{
		topBlock = true;
	}
	else {
		topBlock = false;
	}

	spriteFrame = 15;

	if (topBlock == true)
	{
		spriteFrame = 13;
	}

	//load texture to chunk
	frontSprite.setTexture(tFront);

	frontSprite.setTextureRect(sf::IntRect(spriteFrame * chunkSize, 0, chunkSize, chunkSize));

	frontSprite.setOrigin(originX, originY);
	frontSprite.setPosition(sf::Vector2f(posX, posY));
}

void Chunk::Draw(sf::RenderWindow &window)
{
	Chunk::Update();

	if (front != Chunk::Front::F_NONE)
	{
		window.draw(frontSprite);
	}
}