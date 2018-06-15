
#include "World.h"

World::World(Player *player, PlayerTextureMap *tmap, std::string string)
{
	worldName = string;
	width = 200; // make it even so units are between chunks
	height = 20;//divisible by 4 because origin is 3/4 from bottom of world
	renderRadius = 20;
	chunkSize = 32; //pixels
	chunkRatio = 1; //doubles size of sprite
	chunkSize = chunkSize * chunkRatio;
	playerX = 960;
	playerY = 604;
	spawnWidth = 100;//blocks, this length is represented outside player's window regardless the resolution

	player->playerX = playerX;
	player->playerY = playerY;
	player->leftCollision = false;
	player->rightCollision = false;
	player->bottomCollision = false;
	player->topCollision = false;

	posX = 0;
	posY = 0;

	rect.setSize(sf::Vector2f(64, 160));//player foot position
	rect.setFillColor(sf::Color::Red);
	rect.setOrigin(32, 160);
	rect.setPosition(playerX, playerY);

	/*NOTE: consider doing the initilization of the struct vector
	with no back or front block value so the algorithm for making tunnels and
	shit can know where everything is first*/


	//struct vector initialization
	for (int y = 0; y < height; y++)
	{
		std::vector<ChunkStruct> chunkStructsI;
		for (int x = 0; x < width; x++)
		{
			ChunkStruct chunkStruct;
			chunkStruct.chunkSize = chunkSize;
			chunkStruct.chunkRatio = chunkRatio;
			chunkStruct.originX = -((x - width / 2) * chunkSize); //+ chunkSize;
			chunkStruct.originY = -((y - height / 4) * chunkSize);
			//chunkStruct.originY = -y * chunkSize;
			//cout << chunkStruct.originX << " : " << chunkStruct.originY << " | ";
			chunkStructsI.push_back(chunkStruct);
		}
		chunkStructs.push_back(chunkStructsI);

		for (int x = 0; x < width; x++)
		{
			if (chunkStructs[y][x].originY > 0)
			{
				chunkStructs[y][x].front = ChunkStruct::Front::F_NONE;
				chunkStructs[y][x].collision = false;
			}
			else
			{
				chunkStructs[y][x].front = ChunkStruct::Front::F_GRAVEL;
				chunkStructs[y][x].tFront = tmap->basicBlock;
				chunkStructs[y][x].collision = true;
			}
		}
	}
}

World::~World()
{
	//thingy
}

void World::Update(Clock *clock, Controls *controls, sf::Font &font)
{
	time = clock->time;
}

void World::Draw(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::RenderWindow& window, sf::Font &font, 
	Player *player, PlayerTextureMap *tmap)
{
	World::Update(clock, controls, font);

	player->bottomCollision = false;

	player->Update(clock, controls, window);
	posX = -player->posX + playerX;
	posY = -player->posY + playerY;
	
	Chunk chunk;
	chunk.width = width;
	chunk.height = height;

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

	//World::Collision(clock, player);

	
	for (int y = botY; y < topY; y++)
	{
		for (int x = botX; x < topX; x++)
		{
			chunkStructs[y][x].posX = posX;
			chunkStructs[y][x].posY = posY;
			if (player->posX + chunkStructs[y][x].originX >= -windowX + playerX &&
				player->posX + chunkStructs[y][x].originX <= 32 + windowX - (windowX - playerX) //&& 
				/*player->posY + chunkStructs[y][x].originY >= windowY - (windowX - playerY) &&
				player->posY + chunkStructs[y][x].originX <=  - (windowY - playerY)*/)
			{
				chunk.Draw(x, y, chunkStructs, player, tmap, window);
			}
		}
	}

	//window.draw(rect);
	player->Draw(clock, window);
}