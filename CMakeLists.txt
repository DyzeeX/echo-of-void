cmake_minimum_required(VERSION 3.28)

project(echo-of-void LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable (echo-of-void WIN32
	"main.cpp"
	"Source/Core/Application.cpp"
	"Source/Core/Application.hpp"
	"Source/Core/Config.hpp"
	"Source/Core/ResourceManager.cpp" 
	"Source/Core/ResourceManager.hpp" 
	"Source/Core/WindowManager.cpp"	
	"Source/Core/WindowManager.hpp"	
	"Source/Entities/Enemy/Enemy.cpp"
	"Source/Entities/Enemy/Enemy.hpp"
	"Source/Entities/Player/Player.cpp"
	"Source/Entities/Player/Player.hpp"
	"Source/Entities/Entity.cpp"
	"Source/Entities/Entity.hpp"
	"Source/Input/InputManager.cpp"
	"Source/Input/InputManager.hpp"
	"Source/Particles/Particle.hpp"
	"Source/Particles/Particle.cpp"
	"Source/States/StateManager.cpp"
	"Source/States/StateManager.hpp"
	"Source/UI/HUD.hpp"
	"Source/UI/InventoryUI.hpp"
	"Source/UI/Minimap.hpp"


)

target_compile_features(echo-of-void PRIVATE cxx_std_20)
target_link_libraries(echo-of-void PRIVATE 
	SFML::Graphics
	SFML::Audio
)

if(WIN32)
    target_link_options(echo-of-void PRIVATE 
        $<$<CXX_COMPILER_ID:MSVC>:/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-mwindows>
    )
endif()
