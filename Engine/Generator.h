//generates rooms (solidmaps)

#ifndef GENERATOR_H
#define GENERATOR_H

#include "SolidMap.h"

class Generator
{
public:
	static SolidMap generate(int width, int height);
};

#endif