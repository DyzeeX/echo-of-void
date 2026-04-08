#include "ResourceManager.hpp"

sf::Texture& ResourceManager::LoadTexture(const std::string& id, const std::string& filename) {	return textures.Load(id, filename); }

sf::Font& ResourceManager::LoadFont(const std::string& id, const std::string& filename)       { return fonts.Load(id, filename); }