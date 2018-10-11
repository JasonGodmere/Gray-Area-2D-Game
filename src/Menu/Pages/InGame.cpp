
#include "../Menu.h"

void Menu::InGame(Physics& physics, Controls *controls, Chunk *chunk, sf::RenderWindow& window, 
	Player *player, Textures *textures)
{
	if (chosenPage == Interface::Menu::INGAME &&
		loadedPage != Interface::Menu::INGAME)
	{
		UI.clear();
		count = 0;
		while (true)
		{
			//INTERFACE
			Interface interface(*textures);

			//after pressing escape | for settings etc. in game
			/*if (count == 0)
			{
				interface.type = Interface::Type::BUTTON;
				interface.string = "In Game - " + worlds[worldSelected].worldName;
				interface.characterSize = 120;
				interface.posX = 960;
				interface.posY = 100;
				interface.textColorR = 30;
				interface.textColorG = 30;
				interface.textColorB = 30;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.textColorR = 255;
				interface.textColorG = 255;
				interface.textColorB = 255;
				interface.characterSize = 80;
				UI.push_back(interface);
			}*/

			if (count == 0)
			{
				//title
				interface.type = Interface::Type::TEXT;
				interface.string = "In World - " + worlds[worldSelected].worldName;
				interface.characterSize = 120;
				interface.posX = 960;
				interface.posY = 100;
				interface.textColorR = 30;
				interface.textColorG = 30;
				interface.textColorB = 30;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				interface.textColorR = 255;
				interface.textColorG = 255;
				interface.textColorB = 255;
				interface.characterSize = 80;
				UI.push_back(interface);
			}

			if (count == 1)
			{
				//BACK
				interface.type = Interface::Type::BUTTON;
				interface.buttonType = Interface::ButtonType::SIZE;
				interface.menu = Interface::Menu::STARTPAGE;
				interface.string = "Back";
				interface.characterSize = 50;
				interface.rectColorR = 0;
				interface.rectColorG = 0;
				interface.rectColorB = 0;
				interface.rectColorA = 0;
				interface.posX = 1400;
				interface.posY = 200;
				interface.outlineThickness = 0;
				UI.push_back(interface);
				break;
			}

			count++;
		}
	}

	//worlds[worldSelected].Draw(physics, controls, chunk, window, player, textures);
}