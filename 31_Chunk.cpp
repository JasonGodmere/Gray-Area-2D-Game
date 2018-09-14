
#include "31_Chunk.h"

Chunk::Chunk()
{
	spriteFrame = 0;
}

Chunk::~Chunk()
{
	//thingy
}

void Chunk::Update(PlayerTextureMap *tmap)
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
	//frontSprite.setTexture(chunkStructs[y][x].tFront);

	frontSprite.setTextureRect(sf::IntRect(spriteFrame * chunkSize, 0, chunkSize, chunkSize));

	frontSprite.setOrigin(originX, originY);
	frontSprite.setPosition(sf::Vector2f(posX, posY));
}

void Chunk::Draw(PlayerTextureMap *tmap, sf::RenderWindow &window)
{
	Chunk::Update(tmap);

	if (front != Chunk::Front::F_NONE)
	{
		window.draw(frontSprite);
	}
}