#pragma once

#include "../../Define.h"
#include "../../Textures/Textures.h"
#include "../World.h"

/*
Chunks are the complete contents of world and are all stored. The block class reads the chunks array
to display a screen size part of it.
*/
class ViewChunks : public Chunk
{
private:
	bool rightBlock;//is the block adjacent to the right the same block as this one? if so true etc.
	bool leftBlock;
	bool topBlock;
	bool bottomBlock;
	int spriteFrame;//which frame of the sprite sheet are we using
	sf::Sprite sprite;
	sf::Texture texture;

	const int chunkSize = 32;
	float chunkRatio;

	int width;//in blocks (windowX / (chunkSize * chunkRatio))
	int height;//in blocks

	int originX;
	int originY;

	float posX;
	float posY;

	bool collision = false;

	std::vector<std::vector<Chunk>>& chunks;

	enum Front { NONE, GRAVEL };
	Front front = NONE;

public:
	ViewChunks(int winX, int winY, World& world);

	void Update(float posX, float posY);
	void Draw(float posX, float posY, sf::RenderWindow &window);
};