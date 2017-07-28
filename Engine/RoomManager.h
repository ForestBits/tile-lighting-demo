//the room manager... manages rooms
//specifically, it calls their methods (init, update, draw)
//at the appropriate times
//additionally, it handles transitions from one to another
//and provides a way to goto a different room

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <SFML/Graphics.hpp>
#include "Rooms.h"
#include <vector>

class Room;

class RoomManager
{
	friend int main();

	Room * currentRoom;
	Room * nextRoom;

	bool transitioningOut;
	bool transitioningIn;

	//all transition times are in seconds
	float transitioningInTime;
	float transitioningOutTime;

	sf::Clock clock;


	void update();

	void draw(sf::RenderWindow & window);

public:
	RoomManager(Rooms startRoom);

	bool isTransitioningOut();
	bool isTransitioningIn();

	//both [0, 1]
	float getTransitioningOutPercent();
	float getTransitoningInPercent();

	Room * getRoomByEnum(Rooms room);

	void setRoom(Rooms room);
};

#endif