
#include "30_World.h"

World::World(Player* player, Textures* textures, std::string string)
{
	worldName = string;
	width = 60; // make it even so units are between chunks
	height = 80;//divisible by 4 because origin is 3/4 from bottom of world
	renderRadius = 20;
	chunkSize = 32; //pixels
	chunkRatio = 1; //doubles size of sprite
	chunkSize = chunkSize * chunkRatio;
	playerX = 960;
	playerY = 604;
	spawnWidth = 100;//blocks, this length is represented outside player's window regardless the resolution

	player->playerX = playerX;
	player->playerY = playerY;

	rect.setSize(sf::Vector2f(64, 160));//player foot position
	rect.setFillColor(sf::Color::Red);
	rect.setOrigin(32, 160);
	rect.setPosition(playerX, playerY);

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
				chunks[y][x].front = Chunk::Front::F_NONE;
				chunks[y][x].collision = false;
			}
			else
			{
				chunks[y][x].front = Chunk::Front::F_GRAVEL;
				chunks[y][x].tFront = textures->block->gravel;
				chunks[y][x].collision = true;
			}
		}
	}
}

World::~World()
{
	//thingy
}

void World::Update(Physics& physics, Controls *controls, Textures& textures)
{
	time = physics.time;
}

void World::Draw(Physics& physics, Controls *controls, Chunk* chunk, sf::RenderWindow& window,
	Player *player, Textures* textures)
{
	World::Update(physics, controls, *textures);

	player->Update(physics, controls, chunks, window);
	posX = -player->posX + playerX;
	posY = -player->posY + playerY;

	//values used to determine the region of world needed for entitiesso it doesn't load entire world. 
	//Only what we need for collisions with objects
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
				player->posX + chunks[y][x].originX <= 32 + windowX - (windowX - playerX) //&& 
				/*player->posY + chunkStructs[y][x].originY >= windowY - (windowX - playerY) &&
				player->posY + chunkStructs[y][x].originX <=  - (windowY - playerY)*/)
			{
				chunks[y][x].Draw(window);
			}
		}
	}

	//window.draw(rect);
	player->Draw(physics, window);
}