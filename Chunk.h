#pragma once

#include "Entity.h"
#include "ChunkStruct.h"
#include "Player.h"

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