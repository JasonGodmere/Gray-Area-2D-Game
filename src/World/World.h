#pragma once

#include "Chunk/Chunk.h"
#include "../Entity/Entity.h"

class World : public Chunk
{
public:
	int worldNum;
	int width;
	int height;

	std::string worldName;

	int countX;
	int countY;

	std::vector<std::vector<Chunk>> chunks;
	std::vector<Chunk> chunksI;

	World(Textures* textures, std::string string);
	~World();
};