#include "ResourceManager.hpp"

sf::Texture& ResourceManager::LoadTexture(const std::string& id, const std::string& filename) {	
	return textures.Load(id, filename);
}

sf::Font& ResourceManager::LoadFont(const std::string& id, const std::string& filename) {
	return fonts.Load(id, filename);
}

sf::SoundBuffer& ResourceManager::LoadSound(const std::string& id, const std::string& filename) {
	return sounds.Load(id, filename);
}

void ResourceManager::Init() {
	// load textures
	LoadTexture("icons", "Assets/Textures/set.png");

	// load sounds
	LoadSound("bullet", "Assets/Sounds/gunshot.mp3");

	// load fonts
	LoadFont("main-font", "Assets/Fonts/echo-of-void-font.otf");
}