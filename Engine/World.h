#ifndef WORLD_H
#define WORLD_H

#include "SolidMap.h"
#include "Player.h"
#include <vector>
#include <string>

class World
{
	friend class Renderer;

	std::string name;

	SolidMap solidMap;

	std::vector<Player> players;

public:
	void addPlayer(Player player);

	void removePlayer(Player player);

	void generate(int width, int height);
};


#endif