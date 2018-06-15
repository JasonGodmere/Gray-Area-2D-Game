#pragma once

#include "Entity.h"

class Item : public Entity
{
public:
	int amount;
	int value;

	enum Type { BLOCK, PLACEABLE, WEAPON, CONSUMABLE, AMMO };

	enum Block { GRAVEL };

	Item();
	~Item();

	void Update();
	void Draw(sf::RenderWindow &window);
};