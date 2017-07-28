//2D grid of light values

#ifndef LIGHTMAP_H
#define LIGHTMAP_H

#include <vector>
#include "../Utility/Coord.h"

class LightMap
{
	Coord size;
	
	std::vector<double> lightValues;

public:
	LightMap(int x, int y);

	double get(int x, int y);
	
	void set(int x, int y, double value);

	Coord getSize();
};


#endif