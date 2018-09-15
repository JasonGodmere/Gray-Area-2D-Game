
#include "43_FontTextures.h"

FontTextures::FontTextures()
{
	std::string tfile = "Code Files/Resource Files/fontTextures.json";
	std::ifstream fp(tfile);
	json::json json;
	fp >> json;
	json::json jfont = json["font"];

	if (!this->sansation.loadFromFile(jfont["sansation"])) {
		std::cout << tfile << "\nfont-sansation.ttf Load Error" << std::endl;
		while (true) {}
	}
}