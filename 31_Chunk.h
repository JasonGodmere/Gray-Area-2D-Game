#pragma once

#include "Define.h"
#include "40_Textures.h"

class Chunk
{
public:
	bool rightBlock;//is the block adjacent to the right the same block as this one? if so true etc.
	bool leftBlock;
	bool topBlock;
	bool bottomBlock;

	int spriteFrame;//which frame of the sprite sheet are we using

	int chunkSize;
	float chunkRatio;

	int originX;
	int originY;

	float posX;
	float posY;

	bool player;//temporary for collision

	bool collision = false;

	sf::Sprite frontSprite;
	sf::Text text;

	sf::Texture tFront;

	enum Front { F_NONE, F_GRAVEL };
	Front front = F_NONE;

	Chunk();
	~Chunk();

	void Update();
	void Draw(sf::RenderWindow &window);
};