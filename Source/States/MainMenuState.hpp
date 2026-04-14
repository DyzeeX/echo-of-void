#pragma once

#include "GameState.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public GameState{
public:
    explicit MainMenuState(Application& app);

    void OnEnter() override;
    void OnExit()  override;

    void HandleEvent(const sf::Event& event) override;
    void Update(float dt) override;
    void Render(sf::RenderWindow& window) override;

private:
    sf::Text   m_titleText;
    sf::Text   m_playButton;
    sf::Text   m_exitButton;
    sf::Sprite m_background;
};