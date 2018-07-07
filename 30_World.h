#pragma once

#include "31_Chunk.h"
#include "03_Player.h"

class World : public Chunk
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

	std::vector<std::vector<ChunkStruct>> chunkStructs;
	std::vector<ChunkStruct> chunkStructsI;

	World(Player *player, PlayerTextureMap *tmap, std::string string);
	~World();

	void Collision(Clock *clock, Player *player);

	void Update(Clock *clock, Controls *controls, sf::Font &font);
	void Draw(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::RenderWindow& window, sf::Font &font, 
		Player *player, PlayerTextureMap *tmap);
};