
#include "FontTextures.h"

FontTextures::FontTextures()
{
	std::string tfile = "Code Files/Resource Files/fontTextures.json";
	std::ifstream fp(tfile);
	json::json json = json::json::parse(fp);
	//fp >> json;
	json::json jfont = json["font"];

	if (!this->sansation.loadFromFile(jfont["sansation"])) {
		std::cout << tfile << "\nfont-sansation.ttf Load Error" << std::endl;
		system("PAUSE");
	}
}