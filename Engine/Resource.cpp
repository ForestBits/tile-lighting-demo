#include "Resource.h"

sf::Music Resource::music;

void Resource::loadResources()
{
	music.openFromFile("bgmusic.ogg");
}