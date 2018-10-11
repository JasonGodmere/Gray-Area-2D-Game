
#include "Player.h"

void Player::Building(Controls& controls, World& world)
{
	mouseChunkX = width / 2 - (int)(-(mousePosX - playerX) / 32);//chunk size not 32
	mouseChunkY = height / 4 - (int)(-(mousePosY - playerY) / 32);

	std::cout << mouseChunkX << " : " << mouseChunkY << std::endl;

	block.setSize(sf::Vector2f(32,32));
	block.setPosition(sf::Vector2f(mouseChunkX * 32, mouseChunkY * 32));

	block.setFillColor(sf::Color::White);
}