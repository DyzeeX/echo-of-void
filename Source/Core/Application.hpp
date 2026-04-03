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

	sf::RenderWindow& GetWindow();
	ResourceManager& GetResources();
	InputManager& GetInput();
	StateManager& GetStates();

private:
	void ProcessEvents();
	void Update(float deltaTime);	
	void Render();

	sf::Clock  	     m_clock;
	WindowManager    m_window;
	StateManager     m_states;
	ResourceManager  m_resources;
	InputManager     m_input;
};