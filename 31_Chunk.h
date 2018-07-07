#pragma once

#include "00_Entity.h"
#include "32_ChunkStruct.h"
#include "03_Player.h"

class Chunk : public Entity
{
public:
	bool rightBlock;
	bool leftBlock;
	bool topBlock;
	bool bottomBlock;

	sf::Sprite frontSprite;
	sf::Sprite backSprite;

	Chunk();
	~Chunk();

	void Update(int x, int y, std::vector<std::vector<ChunkStruct>> &chunkStructs, Player *player, PlayerTextureMap *tmap);
	void Draw(int x, int y, std::vector<std::vector<ChunkStruct>> &chunkStructs, Player *player, PlayerTextureMap *tmap, sf::RenderWindow &window);
};