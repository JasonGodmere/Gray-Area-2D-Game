#pragma once

#include "System/System.h"

class Interface : public System
{
public:
	std::vector<Component> components;
	//this includes system because it derives from component

	Interface();

	void Update(Controls& controls, sf::RenderWindow& window);
	//all interface related classes window.draw() in the Update function
};