#pragma once

#include "../Define.h"
#include "Block/BlockTextures.h"
#include "Entity/EntityTextures.h"
#include "Font/FontTextures.h"

class Textures
{
public:
	Textures();
	~Textures();

	BlockTextures* block;
	EntityTextures* entity;
	FontTextures* font;
};