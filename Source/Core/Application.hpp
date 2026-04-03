#pragma once

#include <SFML/Graphics.hpp>

#include "../Core/Config.hpp"
#include "../Core/ResourceManager.hpp"
#include "../Core/WindowManager.hpp"
#include "../States/StateManager.hpp"
#include "../Input/InputManager.hpp"

class Application {
public:
	Application();
	void Run();
	~Application();

	sf::RenderWindow& getWindow();
	ResourceManager& getResources();
	InputManager& getInput();
	StateManager& getStates();

private:
	void ProcessEvents();
	void Update(float deltaTime);	
	void Render();

	sf::RenderWindow   app_window;
	sf::Clock		   app_clock;
	StateManager       app_states;
	ResourceManager    app_resources;
	InputManager       app_input;
};