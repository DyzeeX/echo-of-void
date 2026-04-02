#pragma once

#include <SFML/Graphics.hpp>

#include "Config.hpp"

#include <string>

class Application {
public:
	Application(const std::string& title);
	void Run();
	~Application();

private:
	void ProcessEvents();
	void Update(float deltaTime);
	void Render();

	sf::RenderWindow app_window;
	sf::Clock		 app_clock;
	bool		     app_running = true;
};