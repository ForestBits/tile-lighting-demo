#ifndef OPTIONS_H
#define OPTIONS_H

#include "../Engine/Room.h"

class Options : public Room
{
	

public:
	void update(RoomManager & roomManager);
	void draw(sf::RenderWindow & window, RoomManager & roomManager);
};

#endif