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
		if (frameTime > 0.25f) frameTime = 0.25f;
		accumulator += frameTime;

		m_input.Update();
		ProcessEvents();
		Update(frameTime);
		Render();
	}
}

void Application::ProcessEvents() {
	while (const auto event = m_window.Get().pollEvent())
	{
		m_input.HandleEvent(*event);
	}
}

void Application::Update(float deltaTime) {

	if (m_input.IsKeyDown(sf::Keyboard::Key::Escape))
	{
		std::cout << "Escape was JUST PRESSED!\n";
		m_window.Get().close();
	}

	if (m_input.IsKeyJustReleased(sf::Keyboard::Key::Space))
	{
		std::cout << "space was jsut RELEASED!\n";
	}

	if (m_input.IsKeyJustPressed(sf::Keyboard::Key::Space))
	{
		std::cout << "spsce just PRESSED\n";
	}

	if (m_input.IsKeyDown(sf::Keyboard::Key::Space))
	{
		std::cout << "space is DOWN!\n";
	}

}

void Application::Render() {
	m_window.Get().clear(sf::Color(10, 20, 10));
	m_window.Get().display();
}

// getters
sf::RenderWindow& Application::GetWindow()   { return m_window.Get(); }
ResourceManager& Application::GetResources() { return m_resources; }
InputManager& Application::GetInput()        { return m_input; }
StateManager& Application::GetStates()       { return m_states; }