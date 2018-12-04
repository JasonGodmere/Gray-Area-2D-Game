
#include "../Component/Component.h"

class System : public Component
{
private:
	int columns;
	int maxChar;

public:
	std::vector<Component> components;

	enum TextInput { TEXT_BOX = 0, ACCEPT_BUTTON = 1 };//use as indexes for text input component list, starts at zero

	enum Type { BUTTON_ARRAY, TEXT_INPUT };
//private://value is private but data type is public
	Type type;

public:
	System() {};

	System(std::vector<Component> buttons);

	System(Textures& textures, std::string buttonName, int maxChar, int borderX, int borderY);

	void TextInput(Controls& controls, sf::RenderWindow& window);
	void ButtonArray(Controls& controls, sf::RenderWindow& window);

	void Update(Controls& controls, sf::RenderWindow& window);
	//the systems draw within their respected functions
};