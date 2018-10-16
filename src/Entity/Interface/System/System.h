
#include "../Component/Component.h"

class System : public Component
{
private:


public:
	enum Type { TEXT_INPUT, WORLD_SELECT };
private://value is private but data type is public
	Type type;

public:

	System();

	void TextInput(Controls& controls);
	void ButtonArray(Controls& controls);
};