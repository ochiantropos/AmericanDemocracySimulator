cmake_minimum_required(VERSION 3.17)
project(AmericanDemocracySimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(AmericanDemocracySimulator main.cpp
        lib/Debugger/Debugger.cpp
        lib/Debugger/Debugger.h
        lib/Animations/Animation.cpp
        lib/Animations/Animation.h
        lib/Architect/Scene.cpp
        lib/Architect/Scene.h
        lib/Architect/GameObject.cpp
        lib/Architect/GameObject.h
        lib/Architect/Architect.h
        lib/Architect/AbstractGameObject.h
        lib/Architect/SceneManager.cpp
        lib/Architect/SceneManager.h
        lib/Game.h
        lib/Animations/Animations.h
        lib/Objects/Objects.h
        lib/Objects/WaterPool.cpp
        lib/Objects/WaterPool.h
        lib/Objects/WaterPool.h
        lib/Holders/DrawableHolder.cpp
        lib/Holders/DrawableHolder.h
        lib/Architect/HolderableObject.h
        lib/GameObjects.h
        lib/Animations/WaterAnimation.cpp
        lib/Animations/WaterAnimation.h
        lib/Scenes/GamePlayScene.cpp
        lib/Scenes/GamePlayScene.h
        lib/Objects/Ground.cpp
        lib/Objects/Ground.h
) # add  target

set(SFML_DIR "C:\\AmericanDemocracySimulator\\lib\\SFML\\SFML-2.6.1\\lib\\cmake\\SFML") # link the graphic directory

target_link_libraries(AmericanDemocracySimulator sfml-graphics)

target_include_directories(AmericanDemocracySimulator PUBLIC # add other directory
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Debuger,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Animations,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Architect,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Holders,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Objects,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Scenes
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)