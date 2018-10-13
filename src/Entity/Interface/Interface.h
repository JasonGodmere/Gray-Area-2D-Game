#pragma once

#include "System/System.h"

class Interface : public System
{
public:
	bool recorded;

	int worldNum;

	bool rectCustom;

	int textOriginX;
	int textOriginY;

	bool typing;

	//interface pages


	/* to be deleted
	enum Menu { NONE, EXIT, STARTPAGE, 
		STARTGAME, NAMEWORLD, GENERATEWORLD, LOADGAME, INGAME,//all the different pages within World Select
		ACHIEVEMENTS, 
		SETTINGS };
	Menu menu;

	enum WorldSelect { NEWWORLD, DELETEWORLD, STARTWORLD }; //types of buttons in worldselect page
	WorldSelect worldSelect;

	enum Achievements {  }; //types of buttons in achievements
	Achievements achievements;

	//button type enums

	enum Type { TEXT, BUTTON, TEXTINPUT, WORLDSELECT }; //types of interface items
	Type type;
	*/ //to be deleted

	enum ButtonType { SIZE, COLOR, TOGGLE }; //infers what changes about button when clicked or hovered over
	ButtonType buttonType;

	Interface(Textures& textures);
	~Interface();

	void TextInput(Controls& controls);
	void WorldSelect(Controls& controls);

	void Update(Controls& controls);
	void Draw(Controls& controls, sf::RenderWindow& window);
};