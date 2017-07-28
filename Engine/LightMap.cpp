#include "LightMap.h"
#include "../Utility/DimensionalIndex.h"
#include <cassert>

LightMap::LightMap(int width, int height)  : size(width, height), lightValues(width*height, 0) {}

double LightMap::get(int x, int y)
{
	assert(x >= 0 && y >= 0 && x < size.x && y < size.y);

	Index2D i(size.y);

	return lightValues[i(x, y)];
}

void LightMap::set(int x, int y, double lightValue)
{
	assert(x >= 0 && y >= 0 && x < size.x && y < size.y);

	Index2D i(size.y);

	lightValues[i(x, y)] = lightValue;
}

Coord LightMap::getSize() {return size;}