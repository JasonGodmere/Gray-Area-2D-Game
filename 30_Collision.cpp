
#include "30_World.h"

void World::Collision(Physics& physics, Player *player)
{
	player->grounded = false;

	player->PlayerCollision(physics, chunks, width, height);

	player->playerX = playerX;
	player->playerY = playerY;
}