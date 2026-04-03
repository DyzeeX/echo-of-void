#pragma once

#include <SFML/Graphics.hpp>

#include "../Core/Config.hpp"

class WindowManager {
public:
	WindowManager() = default;
	~WindowManager() = default;

    void Init(unsigned width, unsigned height, const std::string& title);
    void ToggleFullscreen();
    void SetResolution(unsigned width, unsigned height);

    sf::RenderWindow& Get();
    sf::Vector2u      GetSize() const;
    sf::Vector2f      GetCenter() const;
    float             GetAspectRatio() const;

    sf::Vector2f ScreenToWorld(sf::Vector2i screenPos, const sf::View& view) const;

private:
    sf::RenderWindow wm_window;
    bool             wm_fullscreen = false;

};
