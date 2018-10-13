

#include "../../Entity.h"

class Component : public Entity
{
private:
	bool pressed; //button

	std::array<unsigned char, 4> textColorRef = { 255,255,255,255 };//the color reference
	std::array<unsigned char, 4> rectColorRef = { 255,255,255,255 };//the color reference

public:
	virtual void setRectColor(Component& component, unsigned char r, unsigned char g, unsigned char b)
	{
		component.rectColorRef = { r,g,b };
	}
	virtual void setRectColor(Component& component, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		component.rectColorRef = { r,g,b,a };
	}

	virtual void setTextColor(Component& component, unsigned char r, unsigned char g, unsigned char b)
	{
		component.textColorRef = { r,g,b };
	}
	virtual void setTextColor(Component& component, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		component.textColorRef = { r,g,b,a };
	}

	Component();//each type of component should have its own constructor

	void Text();
	void ColorButton(Controls& controls);
	void SizeButton(Controls& controls);
};