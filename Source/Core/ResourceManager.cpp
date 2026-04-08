#include "ResourceManager.hpp"

void ResourceManager::Init() {
	try
	{
		// load textures
		textures.Load("icons", "Textures/set.png");

		// load sounds
		sounds.Load("bullet", "Sounds/gunshot.mp3");

		// load fonts
		fonts.Load("main-font", "Fonts/echo-of-void-font.otf");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

}