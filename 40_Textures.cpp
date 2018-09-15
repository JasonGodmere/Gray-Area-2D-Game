
#include "40_Textures.h"

Textures::Textures()
{
	block = new BlockTextures();
	entity = new EntityTextures();
	font = new FontTextures();
}

Textures::~Textures()
{
	delete block;
	delete entity;
	delete font;
}