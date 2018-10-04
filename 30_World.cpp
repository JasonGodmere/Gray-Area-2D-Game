
#include "30_World.h"

World::World(Textures* textures, std::string string)
{
	worldName = string;
	width = 4000; // make it even so units are between chunks
	height = 1000;//divisible by 4 because origin is 3/4 from bottom of world

	/*
	player->playerX = playerX;
	player->playerY = playerY;
	*/

	//2D chunk "map" initialization into vector
	for (int y = 0; y < height; y++)
	{
		std::vector<Chunk> chunksI;
		for (int x = 0; x < width; x++)
		{
			Chunk chunk;
			chunk.chunkSize = chunkSize;
			chunk.chunkRatio = chunkRatio;
			chunk.originX = -((x - width / 2) * chunkSize);
			chunk.originY = -((y - height / 4) * chunkSize);
			chunksI.push_back(chunk);
		}
		chunks.push_back(chunksI);

		for (int x = 0; x < width; x++)
		{
			if (chunks[y][x].originY > 0)
			{
				chunks[y][x].front = Chunk::Front::NONE;
				chunks[y][x].collision = false;
			}
			else
			{
				chunks[y][x].front = Chunk::Front::GRAVEL;
				chunks[y][x].collision = true;
			}
		}
	}
}

World::~World()
{
	//thingy
}

/*void World::Draw(Chunk* chunk, Textures* textures)
{
	World::Update(*textures);

	player->Update(physics, controls, width, height, chunks, window);
	posX = -player->posX + playerX;
	posY = -player->posY + playerY;

	//values used to determine the region of world needed for entitiesso it doesn't load entire world. 
	//Only what we need for collisions with object

	botX = (player->posX - windowX / 2) / chunkSize - spawnWidth + width / 2;
	topX = (player->posX + windowX / 2) / chunkSize + spawnWidth + width / 2;
	botY = (player->posY - windowY / 2) / chunkSize - spawnWidth + height / 2;
	topY = (player->posY + windowY / 2) / chunkSize + spawnWidth + height / 2;

	if (botY < 0)
	{
		botY = 0;
	}
	if (topY >= height)
	{
		topY = height;
	}
	if (botX < 0)
	{
		botX = 0;
	}
	if (topX >= width)
	{
		topX = width;
	}
	

	World::Collision(physics, player);
	posX = -player->posX + playerX;
	posY = -player->posY + playerY;
	
	for (int y = botY; y < topY; y++)
	{
		for (int x = botX; x < topX; x++)
		{
			chunks[y][x].posX = posX;
			chunks[y][x].posY = posY;
			if (player->posX + chunks[y][x].originX >= -windowX + playerX &&
				player->posX + chunks[y][x].originX <= 32 + windowX - (windowX - playerX)
			{
				chunks[y][x].Draw(window);
			}
		}
	}

	//window.draw(rect);
	player->Draw(physics, window);
	
}*/