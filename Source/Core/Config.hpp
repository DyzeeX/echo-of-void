#pragma once

#include <string_view>

namespace Config {
    
    // window
    constexpr unsigned    WINDOW_W     = 1280u;
    constexpr unsigned    WINDOW_H     = 720u;
    constexpr unsigned    FRAMERATE    = 120u;
    constexpr bool        VSYNC        = false;
    constexpr const char* WINDOW_TITLE = "Echo of Void";
    
    // world
    constexpr int   TILE_SIZE          = 32;
    constexpr int   CHUNK_SIZE         = 16;     
    constexpr float FIXED_DT           = 1.f / 60.f;

    // light
    constexpr float AMBIENT_LIGHT     = 0.04f;
    constexpr int   MAX_LIGHTS        = 64;

    // game
    constexpr float PLAYER_MAX_HP     = 100.f;
    constexpr float PLAYER_MAX_O2     = 100.f;
    constexpr float PLAYER_SPEED      = 90.f;
    constexpr float ENTITY_MAX_HP     = 200.f;
    constexpr float O2_DRAIN_RATE     = 1.25f;

}