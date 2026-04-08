#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Core/ResourceCache.hpp"

class ResourceManager {
public:
	ResourceCache<sf::Texture>     textures;
	ResourceCache<sf::Font>        fonts;
	ResourceCache<sf::SoundBuffer> sounds;

	sf::Texture& LoadTexture(const std::string& id,	const std::string& filename);
	sf::Font&    LoadFont   (const std::string& id, const std::string& filename);
};