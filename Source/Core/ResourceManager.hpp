#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Core/Config.hpp"
#include "Core/ResourceCache.hpp"

class ResourceManager {
public:
	ResourceCache<sf::Texture>     textures;
	ResourceCache<sf::Font>        fonts;
	ResourceCache<sf::SoundBuffer> sounds;
	
	void Init();
};