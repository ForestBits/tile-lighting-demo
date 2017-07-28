//the view is centered on the player

#ifndef PLAYER_H
#define PLAYER_H

#include "SolidMap.h"
#include "../Utility/Coord.h"

class Player
{
	Coord position;

	double lightLevel; //holding a torch in hand, basically
	double lightFlicker; //every call to getLightLevel gives the light which can vary by this amount


public:
	Player(int x, int y, double lightLevel);

	double getLightLevel();

	Coord getPosition();

	bool move(SolidMap solidMap); //returns true when they changed positions, else false
};

#endif