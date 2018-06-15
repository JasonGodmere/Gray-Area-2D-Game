#pragma once

#include "Define.h"

struct ChunkStruct {
	int chunkSize = 1;
	float chunkRatio = 1;

	int originX = 0;
	int originY = 0;

	float posX = 0;
	float posY = 0;

	bool collision = false;

	sf::Texture tFront;
	sf::Texture tBack;

	enum Front { F_NONE, F_GRAVEL };
	Front front = F_NONE;

	enum Back { B_NONE, B_GRAVEL };
	Back back = B_NONE;
};