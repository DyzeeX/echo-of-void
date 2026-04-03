#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

template<typename Resource>
class ResourceCache
{
public:

private:
	std::unordered_map<std::string, std::unique_ptr<Resource>> m_cache;
};

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

private:

};