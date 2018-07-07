
#include "Define.h"
#include "json.hpp"
#include "21_Clock.h"
#include "20_Physics.h"
#include "10_Menu.h"
#include "03_Player.h"

namespace json = nlohmann;

int main(int argc, char *argv[])
{
	enum GameState { EXIT, MENU };
	GameState gameState;
	gameState = MENU;

	int count = 0;

	// create window
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Gray Area", sf::Style::Fullscreen, sf::ContextSettings(24,8,4));
	//-->1920/1080 ratio is 16/9

	sf::Font font;
	
	if (!font.loadFromFile("Code Files/Resource Files/sansation.ttf")) {
		std::cout << "sansation.ttf Load Error" << std::endl;
		return EXIT_FAILURE;
	}

	// event handler
	sf::Event event;

	std::string tfile = "Code Files/Resource Files/textures.json";
	std::ifstream fp(tfile);
	json::json json;
	fp >> json;
	json::json jblock = json["textures"]["block"];

	// load Textures
	PlayerTextureMap tmap;

	if (!tmap.basicBlock.loadFromFile(jblock["gravel"])) {
		std::cout << tfile << "\nBasic Block.png Load Error" << std::endl;
	}

	ChunkStruct chunkStruct;

	Controls controls;

	Menu menu;

	Player player(&tmap);

	Physics physics;

	Clock clock;

	//Game Loop
	while (window.isOpen()) {
		window.clear();

		clock.Update(font);

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		controls.mousePosX = mousePos.x;
		controls.mousePosY = mousePos.y;

		while (window.pollEvent(event))
		{
			controls.Update(event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//Left Click Updater
		if (event.type == sf::Event::EventType::MouseButtonPressed
			&& controls.leftClickToggle == true)
		{
			controls.leftClick = true;
			controls.leftClickToggle = false;
		}
		else
		{
			controls.leftClick = false;
		}

		if (event.type == sf::Event::EventType::MouseButtonReleased
			&& controls.leftClickToggle == false)
		{
			controls.leftClickToggle = true;
		}

		//Menu Page Loader
		switch (gameState)
		{
		case MENU:
			menu.Draw(&clock, &controls, &chunkStruct, font, &player, &tmap, window);
			break;
		}

		//FPS COUNTER
		clock.Draw(font, window);
		
		window.display();

	}

	return 0;
}