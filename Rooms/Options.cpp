#include "Options.h"

void Options::update(RoomManager & roomManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		;//roomManager.setRoom(Rooms::MAIN_MENU);
}

void Options::draw(sf::RenderWindow & window, RoomManager & roomManager)
{
	window.clear(sf::Color::Cyan);
}