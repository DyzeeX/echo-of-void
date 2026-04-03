#include "Application.hpp"

Application::Application() : app_window(sf::VideoMode({Config::WINDOW_W, Config::WINDOW_H}), Config::WINDOW_TITLE) {
	app_window.setFramerateLimit(Config::FRAMERATE);
	app_window.setVerticalSyncEnabled(Config::VSYNC);
	// init ResourceManager
	// init WindowManager
	// inti StateManager
	// init InputManager
}

void Application::Run() {
	
	float accumulator = 0.f;

	while (app_window.isOpen()) {

		float frameTime = app_clock.restart().asSeconds();
		// защита от "spiral of death" — если лагнуло, не догоняем бесконечно
		if (frameTime > 0.25f) frameTime = 0.25f;
		accumulator += frameTime;

		ProcessEvents();

		//while (accumulator >= Config::FIXED_DT) {
		//	app_states.FixedUpdate(Config::FIXED_DT);
		//	accumulator -= Config::FIXED_DT;
		//}
		//app_states.Update(frameTime);

		Update(frameTime);

		Render();
	}
}

void Application::ProcessEvents() {
	while (const auto event = app_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			app_window.close();
	}
}

void Application::Update(float deltaTime) { }

void Application::Render() {
	app_window.clear(sf::Color(10, 20, 10));
	app_window.display();
}

Application::~Application() { }

// getters
sf::RenderWindow& Application::getWindow() { return app_window; }
ResourceManager& Application::getResources() { return app_resources; }
InputManager& Application::getInput() { return app_input; }
StateManager& Application::getStates() { return app_states;  }