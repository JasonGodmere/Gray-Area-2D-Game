#pragma once

#include "Define.h"

class Chunk
{
public:
	bool rightBlock;
	bool leftBlock;
	bool topBlock;
	bool bottomBlock;

	int spriteFrame;

	int chunkSize = 1;
	float chunkRatio = 1;

	int originX = 0;
	int originY = 0;

	float posX = 0;
	float posY = 0;

	bool collision = false;

	sf::Sprite frontSprite;

	sf::Texture tFront;

	enum Front { F_NONE, F_GRAVEL };
	Front front = F_NONE;

	Chunk();
	~Chunk();

	void Update(PlayerTextureMap *tmap);
	void Draw(PlayerTextureMap *tmap, sf::RenderWindow &window);
};