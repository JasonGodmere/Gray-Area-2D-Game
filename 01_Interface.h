#pragma once

#include "00_Entity.h"

class Interface : public Entity
{
public:
	int worldNum;
	bool recorded;

	int maxChar;
	bool pressed; //button
	bool rectCustom;

	int textOriginX;
	int textOriginY;

	int textColorR;
	int textColorG;
	int textColorB;
	int textColorA;

	int rectColorR;
	int rectColorG;
	int rectColorB;
	int rectColorA;

	bool typing;

	//interface pages

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

	enum ButtonType { SIZE, COLOR, TOGGLE }; //infers what changes about button when clicked or hovered over
	ButtonType buttonType;

	Interface(Textures& textures);
	~Interface();

	void Text();
	void TextInput(Controls *controls);
	void ColorButton(Controls *controls);
	void SizeButton(Controls *controls);
	void WorldSelect(Controls *controls);

	void Update(Controls *controls);
	void Draw(Controls *controls, sf::RenderWindow& window);
};