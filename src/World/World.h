#pragma once

#include "StorageChunk/StorageChunk.h"
#include "../Entity/Entity.h"
#include "../Entity/Player/Player.h"

class World : public StorageChunk
{
private:
	int width;
	int height;

	int playerX, playerY;//temporary
	int position[2] = {};//temporary
	int botX, botY, topX, topY;//temporary
public:
	int worldNum;

	std::string worldName;

	int countX;
	int countY;

	std::vector<std::vector<Chunk>> chunks;
	std::vector<Chunk> chunksI;

	World(Textures& textures, std::string string);
	~World();

	void World::Collision(Physics& physics, Player& player);
	void World::Draw(Physics& physics, Controls& controls, Player& player, Chunk& chunk, Textures& textures, sf::RenderWindow& window);

	int getSizeX() { return width; };
	int getSizeY() { return height; };
};