#include "MainMenuState.hpp"
#include <Core/Application.hpp>

MainMenuState::MainMenuState(Application& app) 
	: GameState(app)
	, m_titleText(app.GetResources().fonts.Get("main-font"))
	, m_playButton(app.GetResources().fonts.Get("main-font"))
	, m_exitButton(app.GetResources().fonts.Get("main-font"))
	, m_background(app.GetResources().textures.Get("main-menu-background"))
	{}

void MainMenuState::OnEnter() {
	return;
}

void MainMenuState::OnExit() {
	return;
}

void MainMenuState::HandleEvent(const sf::Event& event) {
	return;
}

void MainMenuState::Update(float dt) {
	return;
}

void MainMenuState::Render(sf::RenderWindow& window) {
	return;
}
