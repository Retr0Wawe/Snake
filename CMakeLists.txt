cmake_minimum_required(VERSION 3.14)

project(Snake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_SHARED_LIBS OFF)

set(SNAKE_INCLUDE
	include/Launcher.hpp
	include/Game.hpp
	include/Snake.hpp
	include/Defines.hpp
)

set(SNAKE_SOURCE
	src/Launcher.cpp
	src/Game.cpp
	src/Snake.cpp
)

add_executable(${PROJECT_NAME}
	${SNAKE_INCLUDE}
	${SNAKE_SOURCE}
	src/main.cpp
)

add_subdirectory(vendor/SFML)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} SFML::Graphics SFML::Audio SFML::Window)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Snake)