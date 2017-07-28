#include "LightList.h"
#include <cassert>

int LightList::getCount() {return lights.size();}

void LightList::clear() {lights.clear();}

void LightList::add(LightSource light) {lights.push_back(light);}

LightSource LightList::get(int index)
{
	assert(index >= 0 && index < lights.size());

	return lights[index];
}

std::vector<LightSource>::iterator LightList::begin() {return lights.begin();}
std::vector<LightSource>::iterator LightList::end() {return lights.end();}