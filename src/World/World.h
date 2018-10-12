#pragma once

#include "Chunk/Chunk.h"
#include "../Entity/Entity.h"

class World : public Chunk
{
private:
	int width;
	int height;
public:
	int worldNum;

	std::string worldName;

	int countX;
	int countY;

	std::vector<std::vector<Chunk>> chunks;
	std::vector<Chunk> chunksI;

	World(Textures* textures, std::string string);
	~World();

	int getSizeX() { return width; };
	int getSizeY() { return height; };
};