
#include "30_World.h"

void World::Collision(Physics& physics, Player *player)
{
	player->grounded = false;

	/*world.Collision() also handles player not stepping off world. If 
	player reaches edge, they stop at edge of screen like in terraria*/

	for (int y = botY; y < topY; y++)
	{
		for (int x = botX; x < topX; x++)
		{
			if (chunks[y][x].collision == true)
			{
				player->PlayerCollision(x, y, physics, chunks);
			}
		}
	}

	if (player->posX + chunks[0][0].originX - windowX / 2 < 0)
	{
		playerX = player->posX + chunks[0][0].originX;
		if (playerX < player->rect.getOrigin().x)
		{
			playerX = player->rect.getOrigin().x;
		}
		if (player->posX < player->rect.getOrigin().x - chunks[0][0].originX)
		{
			player->posX = player->rect.getOrigin().x - chunks[0][0].originX;
		}
	}

	/*if (player->posX + chunkStructs[0][width - 1].originX + chunkSize * chunkRatio + windowX / 2 > width)
	{
		playerX = player->posX + chunkStructs[0][width - 1].originX;
		if (playerX > windowX - player->rect.getOrigin().x)
		{
			playerX = windowX - player->rect.getOrigin().x;
		}
		if (player->posX > player->rect.getSize().x - player->rect.getOrigin().x - chunkStructs[0][width - 1].originX)
		{
			player->posX = player->rect.getSize().x - player->rect.getOrigin().x - chunkStructs[0][width - 1].originX;
		}
	}*/

	player->playerX = playerX;
	player->playerY = playerY;
}