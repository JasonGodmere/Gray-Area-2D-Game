

#include "../../Entity.h"

class Component : public Entity
{
private:
	bool pressed; //button

	std::array<unsigned char, 4> textColorRef = { 255,255,255,255 };//the color reference
	std::array<unsigned char, 4> rectColorRef = { 255,255,255,255 };//the color reference

public: 
	enum Type { NONE, TEXT, COLOR_BUTTON, SIZE_BUTTON };

	int buttonIndex;
	bool border;

	std::array<int, 2> borderSize = {0,0};

private:
	Type type;

public:

	virtual void setRectColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b)
	{
		component.rectColorRef = { r,g,b,255 };
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
		component.textColorRef = { r,g,b,255 };
	}
	virtual void setTextColorRef(Component& component, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		component.textColorRef = { r,g,b,a };
	}
	virtual std::array<unsigned char, 4> getTextColorRef()
	{
		return textColorRef;
	}

	virtual void setType(int i)
	{ 
		Type type = static_cast<Type>(i);
		this->type = type; 
	};
	virtual Type getType() { return type; };

	virtual bool getPressed() { return pressed; };

	Component() {};

	Component(Textures& textures, std::string string, int sizeRatio);//Size Button constructor

	Component(Textures& textures, std::string string, int sizeRatio, std::array<int, 2> borderSize);//Color Button constructor

	virtual void Update(Controls& controls, sf::RenderWindow& window);

	//compenents are drawn in their respected function based on update
	void Text(sf::RenderWindow& window);
	void ColorButton(Controls& controls, sf::RenderWindow& window);
	void SizeButton(Controls& controls, sf::RenderWindow& window);
};