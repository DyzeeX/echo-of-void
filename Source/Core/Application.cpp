#include "Application.hpp"

Application::Application() {
	// init WindowManager
	m_window.Init();
	
	// init ResourceManager
	m_resources.Init();

	// inti StateManager
	// init InputManager
}

void Application::Run() {
	
	float accumulator = 0.f;
	
	while (m_window.Get().isOpen()) {

		float frameTime = m_clock.restart().asSeconds();
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
	while (const auto event = m_window.Get().pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			m_window.Get().close();
	}
}

void Application::Update(float deltaTime) { }

void Application::Render() {
	m_window.Get().clear(sf::Color(10, 20, 10));
	m_window.Get().display();
}

Application::~Application() { }

// getters
sf::RenderWindow& Application::GetWindow()   { return m_window.Get(); }
ResourceManager& Application::GetResources() { return m_resources; }
InputManager& Application::GetInput()        { return m_input; }
StateManager& Application::GetStates()       { return m_states; }