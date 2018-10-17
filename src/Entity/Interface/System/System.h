
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

	System(std::vector<Component> buttons, int columns)
		:columns(columns), components(buttons)
	{
		type = Type::BUTTON_ARRAY;
		//for ButtonArray

		for (int i = 0; i < components.size(); i++)
		{
			
		}
	}

	System(std::string buttonName, int maxChar)
		:maxChar(maxChar)
	{
		type = Type::TEXT_INPUT;
		//for TextInput
	}

	void TextInput(Controls& controls, sf::RenderWindow& window);
	void ButtonArray(Controls& controls, sf::RenderWindow& window);

	void Update(Controls& controls, sf::RenderWindow& window);
	//the systems draw within their respected functions
};