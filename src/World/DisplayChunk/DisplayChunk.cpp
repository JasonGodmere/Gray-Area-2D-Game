
#include "ViewChunks.h"

ViewChunks::ViewChunks(int winX, int winY, World& world)
	:spriteFrame(0), chunks(world.chunks), chunkRatio(1)
{
	/*
	The idea behind this is to generate a screen sized rectangle of sprites 
	that mimics the size, position and orientation of the world chunks. This
	way we only need the amount of sprites necessary to fill the screen at any
	given time, regardless of world size.
	*/

	width = winX / (chunkSize * chunkRatio) + 1;//(rounds up before int width "chops" decimal off)
	height = winY / (chunkSize * chunkRatio) + 1;
}

void ViewChunks::Update(float posX, float posY)
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
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(spriteFrame * chunkSize, 0, chunkSize, chunkSize));

	//sprite.setScale(chunkRatio, chunkRatio);

	sprite.setOrigin(originX, originY);
	sprite.setPosition(sf::Vector2f(posX, posY));
}

void ViewChunks::Draw(float posX, float posY, sf::RenderWindow &window)
{
	ViewChunks::Update(posX, posY);

	if (front != ViewChunks::Front::NONE)
	{
		window.draw(sprite);
	}
}