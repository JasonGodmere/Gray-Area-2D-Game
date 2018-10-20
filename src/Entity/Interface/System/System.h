
#include "../Component/Component.h"

class System : public Component
{
private:
	int columns;
	int maxChar;

	std::vector<Component> components;

public:
	enum Type { BUTTON_ARRAY, TEXT_INPUT };
private://value is private but data type is public
	Type type;

public:
	System() {};

	System(std::vector<Component> buttons, int columns);

	System(std::string buttonName, int maxChar);

	void TextInput(Controls& controls, sf::RenderWindow& window);
	void ButtonArray(Controls& controls, sf::RenderWindow& window);

	void Update(Controls& controls, sf::RenderWindow& window);
	//the systems draw within their respected functions
};