#include "Player.h"
#include "../Utility/Random.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(int x, int y, double lightLevel) : position(x, y), lightLevel(lightLevel),  lightFlicker(0.2) {}

double Player::getLightLevel() 
{
	Random random;

	return lightLevel + (random.nextBool() ? lightFlicker : -lightFlicker);
}

Coord Player::getPosition() {return position;}

bool Player::move(SolidMap solidMap)
{
	bool hasMoved = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (position.x - 1 >= 0 && !solidMap.isSolid(position.x - 1, position.y))
		{
			--position.x;

			hasMoved = true;
		}
	}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (position.x + 1 < solidMap.getSize().x && !solidMap.isSolid(position.x + 1, position.y))
			{
				++position.x;

				hasMoved = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (position.y - 1 >= 0 && !solidMap.isSolid(position.x, position.y - 1))
			{
				--position.y;

				hasMoved = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (position.y + 1 < solidMap.getSize().y && !solidMap.isSolid(position.x, position.y + 1))
			{
				++position.y;

				hasMoved = true;
			}
		}

	return hasMoved;
}


