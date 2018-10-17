

#include "../../Entity.h"

class Component : public Entity
{
private:
	bool pressed; //button

	std::array<unsigned char, 4> textColorRef = { 255,255,255,255 };//the color reference
	std::array<unsigned char, 4> rectColorRef = { 255,255,255,255 };//the color reference

public:
	enum Type { NONE, TEXT, COLOR_BUTTON, SIZE_BUTTON };
private://the enum reference values are known but the stored value stays private
	Type type;

public:
	virtual void setRectColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b)
	{
		component.rectColorRef = { r,g,b };
	}
	virtual void setRectColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		component.rectColorRef = { r,g,b,a };
	}
	virtual std::array<unsigned char, 4> getRectColorRef()
	{
		return rectColorRef;
	}

	virtual void setTextColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b)
	{
		component.textColorRef = { r,g,b };
	}
	virtual void setTextColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		component.textColorRef = { r,g,b,a };
	}
	virtual std::array<unsigned char, 4> getTextColorRef()
	{
		return textColorRef;
	}

	Component() 
	{
		text.setCharacterSize(textSize);
	}

	Component(enum Type& type, std::string& string, int& textSize);//each type of component should have its own constructor

	void Update(Controls& controls, sf::RenderWindow& window);

	//compenents are drawn in their respected function based on update
	void Text(sf::RenderWindow& window);
	void ColorButton(Controls& controls, sf::RenderWindow& window);
	void SizeButton(Controls& controls, sf::RenderWindow& window);
};