#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "../Utility/Coord.h"

struct LightSource
{
	double lightLevel;

	Coord position;

	inline LightSource() {}
	inline LightSource(int x, int y, double lightLevel) : position(x, y), lightLevel(lightLevel) {}

	const static int MAX = 20;
};

#endif