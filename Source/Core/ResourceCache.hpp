#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

namespace LoadChoose {
    template<typename T>
    bool loadResource(T& resource, const std::string& path) {
        return resource.loadFromFile(path);
    }

    template<>
    inline bool loadResource<sf::Font>(sf::Font& font, const std::string& path) {
        return font.openFromFile(path);
    }
}

template<typename Resource>
class ResourceCache
{
public:

    Resource& Load(const std::string& id, const std::string& path) {
        auto it = m_cache.find(id);
        if (it != m_cache.end())
            return *it->second;

        auto resource = std::make_unique<Resource>();
        if (!LoadChoose::loadResource(*resource, path))
            throw std::runtime_error("Failed to load: " + path);

        return *m_cache.emplace(id, std::move(resource)).first->second;
    }

    Resource& Get(const std::string& id) {

        auto it = m_cache.find(id);
        if (it == m_cache.end())
            throw std::runtime_error("Resource not found: " + id);
        return *it->second;
    }

    bool Has(const std::string& id) const { return m_cache.contains(id); }
    void Unload(const std::string& id) { m_cache.erase(id); }
    void Clear() { m_cache.clear(); }

private:
    std::unordered_map<std::string, std::unique_ptr<Resource>> m_cache;
};