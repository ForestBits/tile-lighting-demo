#include "MainMenu.h"
#include "../Engine/Resource.h"
#include <iostream>

MainMenu::MainMenu()
{
	transitionInTime = 0;
	transitionOutTime = 10;

	//Resource::music.play();
}

void MainMenu::update(RoomManager & roomManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		roomManager.setRoom(Rooms::OPTIONS);}
}

void MainMenu::draw(sf::RenderWindow & window, RoomManager & roomManager)
{
	window.clear(sf::Color::Black);

	sf::RectangleShape shape(sf::Vector2f(window.getSize().x, window.getSize().y));

	

	if (roomManager.isTransitioningIn())
		shape.setFillColor(sf::Color(255, 255, 255, roomManager.getTransitoningInPercent()*255));

	if (roomManager.isTransitioningOut())
		shape.setFillColor(sf::Color(255, 255, 255, (1 - roomManager.getTransitioningOutPercent())*255));

	

	sf::Color color = shape.getFillColor();

	window.draw(shape);
}