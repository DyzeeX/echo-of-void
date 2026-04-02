#include "Application.hpp"

Application::Application(const std::string& title) :
					     app_window(sf::VideoMode({Config::WINDOW_W, Config::WINDOW_H}), title) {
	app_window.setVerticalSyncEnabled(true);
}

void Application::Run() {
	while (app_running && app_window.isOpen()) {
		float dt = app_clock.restart().asSeconds();
		ProcessEvents();
		Update(dt);
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