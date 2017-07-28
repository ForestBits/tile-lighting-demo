#include "SolidMap.h"
#include "../Utility/DimensionalIndex.h"
#include <cassert>

SolidMap::SolidMap(int x, int y) : size(x, y), solid(x*y, false) {}

bool SolidMap::isSolid(int x, int y)
{
	//Index2D i(size.y);

	//assert(x >= 0 && y >= 0 && x < size.x && y < size.y);

	

	return solid[size.y * x + y];
}

void SolidMap::setSolid(int x, int y, bool isSolid)
{
	Index2D i(size.y);

	assert(x >= 0 && y >= 0 && x < size.x && y < size.y);

	solid[i(x, y)] = isSolid;
}

Coord SolidMap::getSize() {return size;}