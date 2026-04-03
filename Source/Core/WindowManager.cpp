#include "WindowManager.hpp"

void WindowManager::Init(unsigned width, unsigned height, const std::string& title) {
	wm_window.create(sf::VideoMode({ height, width}), title);
	wm_window.setFramerateLimit(Config::FRAMERATE);
	wm_window.setVerticalSyncEnabled(Config::VSYNC);
}

void WindowManager::ToggleFullscreen() {
	wm_window.setSize(sf::VideoMode::getDesktopMode().size);
}

void WindowManager::SetResolution(unsigned width, unsigned height) {
	wm_window.setSize({ width, height });
}

// getters
sf::RenderWindow& WindowManager::Get() { return wm_window; }

sf::Vector2u WindowManager::GetSize() const { return wm_window.getSize(); }

sf::Vector2f WindowManager::GetCenter() const {
	sf::Vector2u size = wm_window.getSize();
	return { static_cast<float>(size.x) / 2.f,
			 static_cast<float>(size.y) / 2.f };
}

float WindowManager::GetAspectRatio() const {
	sf::Vector2u size = wm_window.getSize();
	return static_cast<float>(size.x) / static_cast<float>(size.y);
}