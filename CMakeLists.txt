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
	"Source/Entities/Entity.cpp"
	"Source/Entities/Entity.hpp"
	"Source/Entities/Player/Player.cpp"
	"Source/Entities/Player/Player.hpp"
	"Source/Particles/Particle.hpp"
	"Source/Particles/Particle.cpp"
 "Source/Core/ResourceManager.cpp" "Source/States/StateManager.cpp")

target_compile_features(echo-of-void PRIVATE cxx_std_20)
target_link_libraries(echo-of-void PRIVATE 
	SFML::Graphics
)

if(WIN32)
    target_link_options(echo-of-void PRIVATE 
        $<$<CXX_COMPILER_ID:MSVC>:/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-mwindows>
    )
endif()
