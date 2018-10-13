#pragma once

#include "../Entity.h"

class Interface : public Entity
{
public:
	bool recorded;

	int worldNum;

	bool pressed; //button
	bool rectCustom;

	int textOriginX;
	int textOriginY;

	std::array<unsigned char, 4> textColor = { 255,255,255,255 };
	std::array<unsigned char, 4> rectColor = { 255,255,255,255 };

	void setRectColor(Interface& interface, unsigned char r, unsigned char g, unsigned char b)
	{
		interface.rectColor = { r,g,b };
	}
	void setRectColor(Interface& interface, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		interface.rectColor = { r,g,b,a };
	}

	void setTextColor(Interface& interface, unsigned char r, unsigned char g, unsigned char b)
	{
		interface.textColor = { r,g,b };
	}
	void setTextColor(Interface& interface, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		interface.textColor = { r,g,b,a };
	}

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
	void TextInput(Controls& controls);
	void ColorButton(Controls& controls);
	void SizeButton(Controls& controls);
	void WorldSelect(Controls& controls);

	void Update(Controls& controls);
	void Draw(Controls& controls, sf::RenderWindow& window);
};