#include "Application.hpp"

Application::Application() {
	app_window.Init(Config::WINDOW_H, Config::WINDOW_W, Config::WINDOW_TITLE);
	// init ResourceManager
	// inti StateManager
	// init InputManager
}

void Application::Run() {
	
	float accumulator = 0.f;

	while (app_window.Get().isOpen()) {

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
	while (const auto event = app_window.Get().pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			app_window.Get().close();
	}
}

void Application::Update(float deltaTime) { }

void Application::Render() {
	app_window.Get().clear(sf::Color(10, 20, 10));
	app_window.Get().display();
}

Application::~Application() { }

// getters
sf::RenderWindow& Application::GetWindow()   { return app_window.Get(); }
ResourceManager& Application::GetResources() { return app_resources; }
InputManager& Application::GetInput()        { return app_input; }
StateManager& Application::GetStates()       { return app_states; }