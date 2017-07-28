//resource cache, of things such as music, sound, or image files

#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Resource
{
	static sf::Music music;


	static void loadResources();
};

#endif