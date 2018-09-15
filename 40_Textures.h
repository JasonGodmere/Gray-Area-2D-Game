#pragma once

#include "Define.h"
#include "41_BlockTextures.h"
#include "42_EntityTextures.h"
#include "43_FontTextures.h"

class Textures
{
public:
	Textures();
	~Textures();

	BlockTextures* block;
	EntityTextures* entity;
	FontTextures* font;
};