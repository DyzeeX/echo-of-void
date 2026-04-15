#pragma once

#include <SFML/Graphics.hpp>

#include <Core/Config.hpp>

class Application;

class GameState {
public:
	explicit GameState(Application& app) : m_app(app) {}
	virtual ~GameState() = default;

	virtual void OnEnter() {}
	virtual void OnExit()  {}

	virtual void HandleEvent(const sf::Event& event) = 0;
	virtual void FixedUpdate(float dt) {}
	virtual void Update(float dt = Config::FIXED_DT) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

	virtual bool IsOverlay() const { return false; }

protected:
	Application& m_app;
};
