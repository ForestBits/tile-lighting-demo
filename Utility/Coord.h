//2D coordinate (or size)

#ifndef COORD_H
#define COORD_H

struct Coord
{
	int x;
	int y;

	inline Coord() {}
	inline Coord(int x, int y) : x(x), y(y) {}
};


#endif