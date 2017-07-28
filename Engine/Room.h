//rooms represent different places, with unique rendering/updates
//often this is synonymous with places in a menu. For example, if you had a
//menu hierarchy that looks like this:
//Main menu
//  Instructions
//  Gameplay
//  Credits
//then you would make a room for each arena
//room are subclasses of this, and are handled by the room manager

#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>

#include "../Engine/RoomManager.h"

class Room
{
protected:
	float transitionInTime;
	float transitionOutTime;

public:
	virtual void update(RoomManager & roomManager) = 0;
	virtual void draw(sf::RenderWindow & window, RoomManager & roomManager) = 0;

	float getTransitionOutTime();
	float getTransitionInTime();
};


#endif