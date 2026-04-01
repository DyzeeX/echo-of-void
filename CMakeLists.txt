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

add_executable (echo-of-void 
	"main.cpp"
	"Source/Entities/Entity.cpp"
	"Source/Entities/Entity.hpp"
	"Source/Entities/Player/Player.cpp"
	"Source/Entities/Player/Player.hpp"
	"Source/Particles/Particle.hpp"
	"Source/Particles/Particle.cpp"
)

target_compile_features(echo-of-void PRIVATE cxx_std_20)
target_link_libraries(echo-of-void PRIVATE 
	SFML::Graphics
)


