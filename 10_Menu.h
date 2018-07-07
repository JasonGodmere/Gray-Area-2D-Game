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

	void StartPage(sf::Font& font);

	void StartGame(sf::Font& font);
	void NameWorld(sf::Font& font);
	void GenerateWorld(sf::Font& font);
	void LoadWorld(sf::Font &font);

	void InGame(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::RenderWindow& window, sf::Font &font, 
		Player *player, PlayerTextureMap *tmap);

	void Achievements(sf::Font& font);

	void Settings(sf::Font& font);

	void Update(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::RenderWindow &window, sf::Font& font, 
		Player *player, PlayerTextureMap *tmap);
	void Draw(Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::Font& font, 
		Player *player, PlayerTextureMap *tmap, sf::RenderWindow& window);

	void ThreadDraw(Menu* menu, Clock *clock, Controls *controls, ChunkStruct *chunkStruct, sf::Font& font,
		Player *player, PlayerTextureMap *tmap, sf::RenderWindow& window); //draws while thread in use for world generation and loading
};