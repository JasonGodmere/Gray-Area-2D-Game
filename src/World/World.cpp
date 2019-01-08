
#include "World.h"

World::World(Textures& textures, std::string string)
{
	worldName = string;

	width = 200; // make it even so units are between chunks
	height = 100; //divisible by 4 because origin is 3/4 from bottom of world

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
			//std::cout << sizeof(chunk) << std::endl;
			chunk.originX = -(x - width / 2);
			chunk.originY = -(y - height / 4);
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

void World::Draw(Physics& physics, Controls& controls, Player& player, Chunk& chunk, Textures& textures, sf::RenderWindow& window)
{
	player.Update(physics, controls, this, window);
	position[0] = -player.position[0] + playerX;
	position[1] = -player.position[1] + playerY;

	//values used to determine the region of world needed for entities so it doesn't load entire world. 
	//Only what we need for collisions with object

	botX = (player.position[0] - 1080/*windowX*/ / 2) / 32/*CHANGE 32*/ - /*spawnWidth*/ + width / 2;
	topX = (player.position[0] + 1080/*windowX*/ / 2) / 32/*CHANGE 32*/ + /*spawnWidth*/ + width / 2;
	botY = (player.position[1] - 1920/*windowY*/ / 2) / 32/*CHANGE 32*/ - /*spawnWidth*/ + height / 2;
	topY = (player.position[1] + 1920/*windowY*/ / 2) / 32/*CHANGE 32*/ + /*spawnWidth*/ + height / 2;

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
	position[0] = -player.position[0] + playerX;
	position[1] = -player.position[1] + playerY;
	
	for (int y = botY; y < topY; y++)
	{
		for (int x = botX; x < topX; x++)
		{
			chunks[y][x].position[0] = posX;
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
	
}