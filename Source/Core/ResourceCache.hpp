#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>

template<typename Resource>
class ResourceCache
{
public:

    Resource& Load(const std::string& id, const std::string& path) {
        auto it = m_cache.find(id);
        if (it != m_cache.end())
            return *it->second;

        auto resource = std::make_unique<Resource>();
        if (!resource->loadFromFile(path))
            throw std::runtime_error("Failed to load: " + path);

        return *m_cache.emplace(id, std::move(resource)).first->second;
    }

    Resource& get(const std::string& id) {
        auto it = m_cache.find(id);
        if (it == m_cache.end())
            throw std::runtime_error("Resource not found: " + id);
        return *it->second;
    }

    bool has(const std::string& id) const { return m_cache.contains(id); }
    void unload(const std::string& id) { m_cache.erase(id); }
    void clear() { m_cache.clear(); }

private:
    std::unordered_map<std::string, std::unique_ptr<Resource>> m_cache;
};