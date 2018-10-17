
#include "../Component/Component.h"

class System : public Component
{
private:
	int columns;
	int maxChar;

public:
	enum Type { BUTTON_ARRAY, WORLD_SELECT };
private://value is private but data type is public
	Type type;

public:
	System() {};

	System(std::vector<Component> buttons, int columns)
		:columns(columns)
	{
		//for ButtonArray
	}

	System(std::string buttonName, int maxChar)
		:maxChar(maxChar)
	{
		//for TextInput
	}

	void TextInput(Controls& controls);
	void ButtonArray(Controls& controls);

	void Update();
	void Draw();
};