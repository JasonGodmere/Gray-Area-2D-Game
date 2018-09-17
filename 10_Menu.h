#pragma once

#include "Arrays.h"
#include "30_World.h"

class Menu : public Arrays
{
public:
	bool threading;

	int maxWorlds;
	int worldNum;
	int worldSelected;
	int count;
	int count2;
	int elements;

	Interface::Menu chosenPage;
	Interface::Menu loadedPage;

	std::vector<World> worlds;
	std::vector<World>::iterator worldsIter;

	Menu();
	~Menu();

	void StartPage(Textures& textures);

	void StartGame(Textures& textures);
	void NameWorld(Textures& textures);
	void GenerateWorld(Textures& textures);
	void LoadWorld(Textures& textures);

	void InGame(Physics& physics, Controls* controls, Chunk* chunk, sf::RenderWindow& window, 
		Player *player, Textures* textures);

	void Achievements(Textures& textures);

	void Settings(Textures& textures);

	void Update(Physics& physics, Controls *controls, Chunk *chunk, sf::RenderWindow &window,
		Player *player, Textures* textures);
	void Draw(Physics& physics, Controls *controls, Chunk *chunk, Player *player, 
		Textures* textures, sf::RenderWindow& window);

	void ThreadDraw(Menu* menu, Physics& physics, Controls *controls, Chunk *chunk, Player *player, 
		Textures *textures, sf::RenderWindow& window); //draws while thread in use for world generation and loading
};