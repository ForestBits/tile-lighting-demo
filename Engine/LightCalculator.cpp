#include "LightCalculator.h"
#include <cassert>
#include <cmath>

LightMap calculateLighting(SolidMap solid, LightList lights)
{
	LightMap lightMap(solid.getSize().x, solid.getSize().y);

	for (auto light : lights)
	{
		//not really sure what would happen if it was out of bounds
		assert(light.position.x >= 0 && light.position.y >= 0 && light.position.x < lightMap.getSize().x && light.position.y < lightMap.getSize().y); 

		recursiveLightCalculation(light.position.x, light.position.y, light.lightLevel, lightMap, solid);
	}

	for (int x = 0; x < lightMap.getSize().x; ++x)
		for (int y = 0; y < lightMap.getSize().y; ++y)
			if (lightMap.get(x, y) > LightSource::MAX)
				lightMap.set(x, y, LightSource::MAX);

	return lightMap;
}

void recursiveLightCalculation(int x, int y,  double lightLevel, LightMap & lightMap, SolidMap & solid)
{
	//if the light is brighter here, then it already calculated all that this would
	if (lightLevel <= lightMap.get(x, y))
		return;

	
	lightMap.set(x, y, lightLevel);

	if (x - 1 >= 0 && !solid.isSolid(x - 1, y))
		recursiveLightCalculation(x - 1, y, lightLevel - 1, lightMap, solid);

	if (y - 1 >= 0 && !solid.isSolid(x, y - 1))
		recursiveLightCalculation(x, y - 1, lightLevel - 1, lightMap, solid);

	if (x + 1 < lightMap.getSize().x && !solid.isSolid(x + 1, y))
		recursiveLightCalculation(x + 1, y, lightLevel - 1, lightMap, solid);

	if (y + 1 < lightMap.getSize().y && !solid.isSolid(x, y + 1))
		recursiveLightCalculation(x, y + 1, lightLevel - 1, lightMap, solid);

	if (x - 1 >= 0 && y - 1 >= 0 && !solid.isSolid(x - 1, y - 1))
		recursiveLightCalculation(x - 1, y - 1, lightLevel - std::sqrt(2), lightMap, solid);

	if (x - 1 >= 0 && y + 1 < lightMap.getSize().y && !solid.isSolid(x - 1, y + 1))
		recursiveLightCalculation(x - 1, y + 1, lightLevel - std::sqrt(2), lightMap, solid);

	if (x + 1 < lightMap.getSize().x && y - 1 >= 0 && !solid.isSolid(x + 1, y - 1))
		recursiveLightCalculation(x + 1, y - 1, lightLevel - std::sqrt(2), lightMap, solid);

	if (x + 1 < lightMap.getSize().x && y + 1 < lightMap.getSize().y && !solid.isSolid(x + 1, y + 1))
		recursiveLightCalculation(x + 1, y + 1, lightLevel - std::sqrt(2), lightMap, solid);
}