
#include "03_Player.h"

void Player::Building(Controls& controls, World& world)
{
	mouseChunkX = width / 2 - (int)(-(mousePosX - playerX) / world.chunks[0][0].chunkSize);
	mouseChunkY = height / 4 - (int)(-(mousePosY - playerY) / world.chunks[0][0].chunkSize);

	std::cout << mouseChunkX << " : " << mouseChunkY << std::endl;

	block.setSize(sf::Vector2f(32,32));
	block.setPosition(sf::Vector2f(mouseChunkX * 32, mouseChunkY * 32));

	block.setFillColor(sf::Color::White);
}