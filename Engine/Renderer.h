#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

class Renderer
{
	const static int TILESIZE = 16;

	sf::RenderWindow & window;

public:
	Renderer(sf::RenderWindow & window);

	void draw(World world);
};

#endif