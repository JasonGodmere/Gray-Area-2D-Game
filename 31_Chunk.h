#pragma once

#include "Define.h"

/*
Chunks are the complete contents of world and are all stored. The block class reads the chunks array
to display a screen size part of it.
*/
struct Chunk
{
public:
	//only for view block
	bool rightBlock;//is the block adjacent to the right the same block as this one? if so true etc.
	bool leftBlock;
	bool topBlock;
	bool bottomBlock;
	int spriteFrame;//which frame of the sprite sheet are we using
	sf::Sprite frontSprite;
	sf::Texture tFront;
	//---------------

	int chunkSize;
	float chunkRatio;

	int originX;
	int originY;

	bool collision = false;

	enum Front { NONE, GRAVEL };
	Front front = NONE;
};