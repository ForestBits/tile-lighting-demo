#ifndef LIGHTCALCULATOR_H
#define LIGHTCALCULATOR_H

#include "LightMap.h"
#include "SolidMap.h"
#include "LightList.h"

LightMap calculateLighting(SolidMap solid, LightList lights);

void recursiveLightCalculation(int x, int y,  double lightLevel, LightMap & lightMap, SolidMap & solid);

#endif