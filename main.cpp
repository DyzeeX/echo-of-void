#include <iostream>
#include "Source/Entities/Entity.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/GpuPreference.hpp>

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

int main()
{
	Entity ent;
	std::cout << "Hello CMake." << std::endl;


	sf::RenderWindow window(sf::VideoMode({ 900u, 600u }), "SFML works!");
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
