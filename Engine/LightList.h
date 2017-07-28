//holds list of light sources

#ifndef LIGHTLIST_H
#define LIGHTLIST_H

#include <vector>
#include "LightSource.h"

class LightList
{
	std::vector<LightSource> lights;

public:
	int getCount();

	LightSource get(int index);

	void add(LightSource light);

	void clear();

	std::vector<LightSource>::iterator begin();
	std::vector<LightSource>::iterator end();

};


#endif
