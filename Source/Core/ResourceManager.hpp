#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Core/Config.hpp"
#include "../Core/ResourceCache.hpp"

class ResourceManager {
public:
	ResourceCache<sf::Texture>     textures;
	ResourceCache<sf::Font>        fonts;
	ResourceCache<sf::SoundBuffer> sounds;
	
	void Init();

private:
	sf::Texture&	  LoadTexture (const std::string& id, const std::string& filename);
	sf::Font&		  LoadFont    (const std::string& id, const std::string& filename);
	sf::SoundBuffer&  LoadSound	  (const std::string& id, const std::string& filename);
};