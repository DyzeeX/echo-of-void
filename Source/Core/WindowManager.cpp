#include "WindowManager.hpp"

void WindowManager::Init(unsigned width, unsigned height, const std::string& title) {
	m_window.create(sf::VideoMode({ width, height }), title);
	m_window.setFramerateLimit(Config::FRAMERATE);
	m_window.setVerticalSyncEnabled(Config::VSYNC);
}

// some shit, go back later
//void WindowManager::ToggleFullscreen() {
//}

void WindowManager::SetResolution(unsigned width, unsigned height) {
	m_window.setSize({ width, height });
}

// getters
sf::RenderWindow& WindowManager::Get() { return m_window; }

sf::Vector2u WindowManager::GetSize() const { return m_window.getSize(); }

sf::Vector2f WindowManager::GetCenter() const {
	sf::Vector2u size = m_window.getSize();
	return { static_cast<float>(size.x) / 2.f,
			 static_cast<float>(size.y) / 2.f };
}

float WindowManager::GetAspectRatio() const {
	sf::Vector2u size = m_window.getSize();
	return static_cast<float>(size.x) / static_cast<float>(size.y);
}