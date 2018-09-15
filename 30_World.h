#pragma once

#include "31_Chunk.h"
#include "00_Entity.h"
#include "03_Player.h"

class World : public Entity
{
public:
	int windowX = 0;
	int windowY = 0;

	//for calculating which chunks we need for collisions and enemy spawn
	//finding if chunk x is within the ebemy spawn region
	int botY;
	int topY;
	int botX;
	int topX;

	int playerX; //on screen
	int playerY; //on screen
	int worldNum;
	int width;
	int height;
	int renderRadius;
	float chunkRatio;
	int chunkSize;
	int spawnWidth;

	float chunksX;
	float chunksY;

	std::string worldName;

	int countX;
	int countY;

	std::vector<std::vector<Chunk>> chunks;
	std::vector<Chunk> chunksI;

	World(Player* player, Textures* textures, std::string string);
	~World();

	void Collision(Clock* clock, Player* player);

	void Update(Clock *clock, Controls *controls, Textures& textures);
	void Draw(Clock *clock, Controls *controls, Chunk* chunk, sf::RenderWindow& window,
		Player *player, Textures* textures);
};