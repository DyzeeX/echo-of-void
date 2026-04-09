#include "InputManager.hpp"

void InputManager::Update() {
	m_keyPrevious = m_keyCurrent;
	m_mousePrevious = m_mouseCurrent;
	m_mousePrevPos = m_mousePos;

	for (auto& [key, state] : m_keyCurrent) {
		state = sf::Keyboard::isKeyPressed(key);
	}

	for (auto& [btn, state] : m_mouseCurrent) {
		state = sf::Mouse::isButtonPressed(btn);
	}

	m_mousePos = GetMousePosition();
}

void InputManager::HandleEvent(const sf::Event& event) {
	if (const auto* e = event.getIf<sf::Event::KeyPressed>()) {
		m_keyCurrent[e->code] = true;
	}

	if (const auto* e = event.getIf<sf::Event::KeyReleased>()) {
		m_keyCurrent[e->code] = false;
	}

	if (const auto* e = event.getIf<sf::Event::MouseButtonPressed>()) {
		m_mouseCurrent[e->button] = true;
	}

	if (const auto* e = event.getIf<sf::Event::MouseButtonReleased>()) {
		m_mouseCurrent[e->button] = false;
	}
}

bool InputManager::IsKeyDown(sf::Keyboard::Key key) const {
	auto it = m_keyCurrent.find(key);
	return it != m_keyCurrent.end() && it->second;
}

bool InputManager::IsKeyJustPressed(sf::Keyboard::Key key) const {
	bool curr = IsKeyDown(key);
	auto it   = m_keyPrevious.find(key);
	bool prev = it != m_keyPrevious.end() && it->second;
	return curr && !prev;
}

bool InputManager::IsKeyJustReleased(sf::Keyboard::Key key) const {
	bool curr = IsKeyDown(key);
	auto it = m_keyPrevious.find(key);
	bool prev = it != m_keyPrevious.end() && it->second;
	return !curr && prev;
}

bool InputManager::IsMouseDown(sf::Mouse::Button btn) const {
	auto it = m_mouseCurrent.find(btn);
	return it != m_mouseCurrent.end() && it->second;
}

bool InputManager::IsMouseJustPressed(sf::Mouse::Button btn) const {
	bool curr = IsMouseDown(btn);
	auto it   = m_mousePrevious.find(btn);
	bool prev = it != m_mousePrevious.end() && it->second;
	return curr && !prev;
}

bool InputManager::IsMouseJustReleased(sf::Mouse::Button btn) const {
	bool curr = IsMouseDown(btn);
	auto it = m_mousePrevious.find(btn);
	bool prev = it != m_mousePrevious.end() && it->second;
	return !curr && prev;
}

sf::Vector2i InputManager::GetMousePosition() const { 
	return sf::Mouse::getPosition(); 
}

sf::Vector2f InputManager::GetMouseDelta() const {
	return sf::Vector2f(
		static_cast<float>(m_mousePos.x - m_mousePrevPos.x),
		static_cast<float>(m_mousePos.y - m_mousePrevPos.y));
}

sf::Vector2f InputManager::GetMouseWorldPosition(const sf::View& view, const sf::RenderWindow& window) const {
	return window.mapPixelToCoords(m_mousePos, view);
}