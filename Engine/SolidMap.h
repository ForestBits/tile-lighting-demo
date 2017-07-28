//2D maps of solids (blocks light), and non-solids (light passes through

#ifndef SOLIDMAP_H
#define SOLIDMAP_H

#include <vector>
#include "../Utility/DimensionalIndex.h"
#include "../Utility/Coord.h"

class SolidMap
{
	std::vector<bool> solid;

	Coord size;

public:
	SolidMap(int width, int height);

	bool isSolid(int x, int y);

	void setSolid(int x, int y, bool solid);

	Coord getSize();
};


#endif