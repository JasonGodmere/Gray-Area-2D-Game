
#include "Chunk.h"

Chunk::Chunk()
{
	spriteFrame = 0;
}

Chunk::~Chunk()
{
	//thingy
}

void Chunk::Update(int x, int y, std::vector<std::vector<ChunkStruct>> &chunkStructs, Player *player, PlayerTextureMap *tmap)
{
	originX = chunkStructs[y][x].originX;
	originY = chunkStructs[y][x].originY;

	posX = chunkStructs[y][x].posX;
	posY = chunkStructs[y][x].posY;
	
	/*topBlock = false;
	bottomBlock = false;
	leftBlock = false;
	rightBlock = false;

	if (y + 1 >= height)
	{
		topBlock = true;
	}
	else if (chunkStructs[y+1][x].front == )*/

	if (chunkStructs[y][x].originY == 0)
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
	frontSprite.setTexture(chunkStructs[y][x].tFront);

	frontSprite.setTextureRect(sf::IntRect(spriteFrame * chunkStructs[y][x].chunkSize, 0, chunkStructs[y][x].chunkSize, chunkStructs[y][x].chunkSize));

	frontSprite.setOrigin(originX, originY);
	frontSprite.setPosition(sf::Vector2f(posX, posY));
}

void Chunk::Draw(int x, int y, std::vector<std::vector<ChunkStruct>> &chunkStructs, Player *player, PlayerTextureMap *tmap, sf::RenderWindow &window)
{
	Chunk::Update(x, y, chunkStructs, player, tmap);

	if (chunkStructs[y][x].back != ChunkStruct::Back::B_NONE)
	{
		window.draw(backSprite);
	}
	if (chunkStructs[y][x].front != ChunkStruct::Front::F_NONE)
	{
		window.draw(frontSprite);
	}
}