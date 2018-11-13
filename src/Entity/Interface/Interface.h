#pragma once

#include "System/System.h"

class Interface : public System
{
public:
	std::vector<Component> components;
	std::vector<System> systems;
	//this includes system because it derives from component

	Interface() {};

	virtual void ClearItems();

	virtual void Update(Controls& controls, sf::RenderWindow& window);
	//all interface related classes window.draw() in the Update function
};