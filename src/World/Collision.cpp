#include "World.h"

void World::Collision(Physics& physics, Player& player)
{
	player.Collision(physics, this);
	
	//player->playerX = playerX;
	//player->playerY = playerY;
}