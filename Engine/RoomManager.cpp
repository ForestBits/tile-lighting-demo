#include "RoomManager.h"
#include "../Rooms/MainMenu.h"
#include "../Rooms/Options.h"
#include <iostream>

Room * RoomManager::getRoomByEnum(Rooms room)
{
	switch (room)
	{
	case Rooms::MAIN_MENU:
		return new MainMenu();

		break;

	case Rooms::OPTIONS:
		return new Options();

		break;
	}
}

RoomManager::RoomManager(Rooms startRoom) : transitioningOut(false), transitioningIn(true), transitioningOutTime(0), transitioningInTime(0)
{
	currentRoom = getRoomByEnum(startRoom);
}

bool RoomManager::isTransitioningOut() {return transitioningOut;} 
bool RoomManager::isTransitioningIn() {return transitioningIn;}

float RoomManager::getTransitioningOutPercent()
{
	if (!transitioningOut)
		return 0;

	return transitioningOutTime/currentRoom->getTransitionOutTime();
}

float RoomManager::getTransitoningInPercent()
{
	if (!transitioningIn)
		return 0;

	return transitioningInTime/currentRoom->getTransitionInTime();
}

void RoomManager::setRoom(Rooms room)
{
	if (transitioningIn || transitioningOut)
		return;
	std::cout << "Switchin' rooms\n";
	nextRoom = getRoomByEnum(room);

	transitioningOut = true;

	transitioningOutTime = 0;
}

void RoomManager::update()
{
	float timePassed = clock.getElapsedTime().asSeconds();

	clock.restart();

	if (transitioningOut)
	{
		transitioningOutTime += timePassed;

		if (transitioningOutTime >= currentRoom->getTransitionOutTime())
		{
			transitioningOut = false;
			transitioningIn = true;

			currentRoom = nextRoom;
			nextRoom = nullptr;

			transitioningOutTime = 0;
			transitioningInTime = currentRoom->getTransitionInTime();
		}
	}
	else if (transitioningIn)
	{
		transitioningInTime += timePassed;

		if (transitioningInTime >= currentRoom->getTransitionInTime())
		{
			transitioningIn = false;
		}
	}

	currentRoom->update(*this);
}

void RoomManager::draw(sf::RenderWindow & window) 
{
	currentRoom->draw(window, *this);

	window.display();
}
