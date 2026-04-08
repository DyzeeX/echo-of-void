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
	"Source/Core/ResourceManager.cpp" 
	"Source/Core/WindowManager.cpp"	
	"Source/Entities/Enemy/Enemy.cpp"
	"Source/Entities/Player/Player.cpp"
	"Source/Entities/Entity.cpp"
	"Source/Input/InputManager.cpp"
	"Source/Particles/Particle.cpp"
	"Source/States/StateManager.cpp"

)

target_include_directories(echo-of-void PRIVATE "Source")

target_compile_features(echo-of-void PRIVATE cxx_std_20)
target_link_libraries(echo-of-void PRIVATE 
	SFML::Graphics
	SFML::Audio
	SFML::System
    SFML::Window
)

if(MSVC)
    set_target_properties(echo-of-void PROPERTIES 

        LINK_FLAGS_DEBUG          "/SUBSYSTEM:CONSOLE"
        LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE"
        LINK_FLAGS_RELEASE        "/SUBSYSTEM:WINDOWS"
        LINK_FLAGS_MINSIZEREL     "/SUBSYSTEM:WINDOWS"
        
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
    )
endif()

set(ASSETS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Assets")
#set(SHADERS_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Shaders")

add_custom_command(TARGET echo-of-void POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_SOURCE_DIR}
    $<TARGET_FILE_DIR:echo-of-void>)