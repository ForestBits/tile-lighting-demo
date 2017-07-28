#include <SFML/Graphics.hpp>
#include "Utility/Random.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Engine/LightList.h"
#include "Engine/LightSource.h"
#include "Engine/SolidMap.h"
#include "Engine/Generator.h"
#include "Engine/LightCalculator.h"
#include <cassert>
#include "Engine/Player.h"
#include "Engine/RoomManager.h"
#include "Engine/Resource.h"

void drawBlock(int x, int y, sf::Color color, sf::RenderWindow & window)
{
	static sf::RectangleShape rectangle(sf::Vector2f(20, 20));

	rectangle.setFillColor(color);

	rectangle.setPosition(20*x, 20*y);

	window.draw(rectangle);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Light Maze");

	/*Resource::loadResources();

	//RoomManager roomManager(Rooms::MAIN_MENU);

	sf::Clock draw;
	sf::Clock update;

	while (true)
	{
		if (update.getElapsedTime().asSeconds() > 0.03)
		{
			update.restart();

			//roomManager.update();
		}

		if (draw.getElapsedTime().asSeconds() > 0.03)
		{
			draw.restart();

			//roomManager.draw(window);
		}




		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	*/
	window.setFramerateLimit(30);

	SolidMap solidMap = Generator::generate(25, 25);
	LightList lightList;
	Player player(13, 13, 20);

	lightList.add(LightSource(player.getPosition().x, player.getPosition().y, player.getLightLevel()));

	LightMap lightMap = calculateLighting(solidMap, lightList);

	while (true)
	{
		player.move(solidMap);	

			lightList.clear();

			lightList.add(LightSource(player.getPosition().x, player.getPosition().y, player.getLightLevel()));

			lightMap = calculateLighting(solidMap, lightList);

		

		window.clear(sf::Color::Black);

		for (int x = 0; x < 25; ++x)
			for (int y = 0; y < 25; ++y)
				drawBlock(x, y*25, sf::Color::Black, window);

		for (int x = 0; x < 25; ++x)
			for (int y = 0; y < 25; ++y)
			{
				if (solidMap.isSolid(x, y))
					continue;

				sf::Color color = sf::Color::White;				

				color.a = (lightMap.get(x, y)/LightSource::MAX)*255;

				drawBlock(x, y, color, window);
			}

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return 0;
		}

		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}



	return 0;
}

