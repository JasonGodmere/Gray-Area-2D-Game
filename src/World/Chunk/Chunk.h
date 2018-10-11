#pragma once

#include "../../Define.h"

/*
Since the entire world needs to be stored with the Chunk data type
it is as minimalistic as possible to reduce data size
*/

struct Chunk
{
public:
	int originX;
	int originY;

	bool collision = false;

	enum Front { NONE, GRAVEL };
	Front front = NONE;
};