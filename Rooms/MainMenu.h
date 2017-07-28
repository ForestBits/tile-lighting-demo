#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Engine/Room.h"

class MainMenu : public Room
{


public:
	MainMenu();
	void update(RoomManager & roomManager);
	void draw(sf::RenderWindow & window, RoomManager & roomManager);
};

#endif