#include "Generator.h"
#include "../Utility/Random.h"

SolidMap Generator::generate(int width, int height)
{
	Random random;

	SolidMap solidMap(width, height);

	for (int x = 1; x < width; x += 2)
		for (int y = 0; y < height; ++y)
			if (random.irandom_range(0, 1) == 1)
				solidMap.setSolid(x, y, true);

	for (int x = 0; x < solidMap.getSize().x; ++x)
		for (int y = 0; y < solidMap.getSize().y; ++y)
		{
			int touchCount = 0;

			if (x - 1 > 0 && solidMap.isSolid(x - 1, y))
				++touchCount;

			if (y - 1 > 0 && solidMap.isSolid(x, y - 1))
				++touchCount;

			if (x + 1 < solidMap.getSize().x && solidMap.isSolid(x + 1, y))
				++touchCount;

			if (y + 1 < solidMap.getSize().y && solidMap.isSolid(x, y + 1))
				++touchCount;

			if (touchCount == 0)
				solidMap.setSolid(x, y, false);

			if (touchCount >= 3)
				solidMap.setSolid(x, y, true);
		}

	return solidMap;
}