#pragma once 

#include <SFML/Graphics.hpp>
#include <unordered_map>	

#include <iostream>

class InputManager {
public:

	void Update();

	void HandleEvent(const sf::Event& event);

	// keyboard
	bool IsKeyDown        (sf::Keyboard::Key key) const;
	bool IsKeyJustPressed (sf::Keyboard::Key key) const;
	bool IsKeyJustReleased(sf::Keyboard::Key key) const;

	// mouse 
	bool IsMouseDown        (sf::Mouse::Button btn) const;
	bool IsMouseJustPressed (sf::Mouse::Button btn) const;
	bool IsMouseJustReleased(sf::Mouse::Button key) const;


	sf::Vector2i GetMousePosition() const;
	sf::Vector2f GetMouseWorldPosition(const sf::View& view,
									   const sf::RenderWindow& window) const;
	sf::Vector2f GetMouseDelta() const;
private:
	std::unordered_map<sf::Keyboard::Key, bool> m_keyCurrent;
	std::unordered_map<sf::Keyboard::Key, bool> m_keyPrevious;

	std::unordered_map<sf::Mouse::Button, bool> m_mouseCurrent;
	std::unordered_map<sf::Mouse::Button, bool> m_mousePrevious;

	sf::Vector2i m_mousePos;
	sf::Vector2i m_mousePrevPos;
};