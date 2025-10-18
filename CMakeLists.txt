cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
else()
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(HardMode VERSION 1.0.0)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Set up the mod binary
file(GLOB_RECURSE SOURCES
	src/*.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
 "src/Layers/CreditsLayer.h" "src/Hooks/LevelSelectLayer.cpp" "src/Hooks/LoadingLayer.cpp" "src/Hooks/LevelPage.cpp" "src/Hooks/LevelTools.cpp" "src/Hooks/LocalLevelManager.cpp" "src/Hooks/CurrencySprite.cpp" "src/Hooks/MenuLayer.cpp" "src/Hooks/GameManager.cpp" "src/Hooks/CurrencyRewardLayer.cpp" "src/Hooks/PlayLayer.cpp" "src/Hooks/OptionsLayer.cpp" "src/Hooks/ProfilePage.cpp")
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Set up dependencies, resources, and link Geode.
setup_geode_mod(${PROJECT_NAME})
