
#include "BlockTextures.h"

BlockTextures::BlockTextures()
{
	std::string tfile = "Code Files/Resource Files/blockTextures.json";
	std::ifstream fp(tfile);
	json::json json;
	fp >> json;
	json::json jblock = json["block"];

	if (!this->gravel.loadFromFile(jblock["gravel"])) {
		std::cout << tfile << "\nblock-gravel.png Load Error" << std::endl;
		system("PAUSE");
	}
}