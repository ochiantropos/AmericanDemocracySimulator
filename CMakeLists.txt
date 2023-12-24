cmake_minimum_required(VERSION 3.17)
project(AmericanDemocracySimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(AmericanDemocracySimulator main.cpp
        lib/Debugger/Debugger.cpp
        lib/Debugger/Debugger.h
        lib/Architect/Objects/Animations/Animation.cpp
        lib/Architect/Objects/Animations/Animation.h
        lib/Architect/Scenes/Scene.cpp
        lib/Architect/Scenes/Scene.h
        lib/Architect/Architect.h
        lib/Architect/Base/AbstractGameObject.h
        lib/Architect/Base/SceneManager.cpp
        lib/Architect/Base/SceneManager.h
        lib/Game.h
        lib/Architect/Objects/Animations/Animations.h
        lib/Architect/Objects/Objects.h
        lib/Architect/Objects/GameObjects/WaterPool.cpp
        lib/Architect/Objects/GameObjects/WaterPool.h
        lib/Architect/Objects/GameObjects/WaterPool.h
        lib/Architect/Holders/DrawableHolder.cpp
        lib/Architect/Holders/DrawableHolder.h
        lib/Architect/Objects/Animations/WaterAnimation.cpp
        lib/Architect/Objects/Animations/WaterAnimation.h
        lib/Architect/Scenes/GamePlayScene.cpp
        lib/Architect/Scenes/GamePlayScene.h
        lib/Architect/Objects/GameObjects/Ground.cpp
        lib/Architect/Objects/GameObjects/Ground.h
        lib/Architect/Objects/Animations/GroundAnimation.cpp
        lib/Architect/Objects/Animations/GroundAnimation.h
        lib/Architect/Objects/Animations/GroundAnimation.h
        lib/Architect/Objects/GameObjects/Ship.cpp
        lib/Architect/Objects/GameObjects/Ship.h
        lib/Architect/Objects/GameObjects/ShipDieAnimated.cpp
        lib/Architect/Objects/GameObjects/ShipDieAnimated.h
        lib/Architect/Holders/SceneHolder.cpp
        lib/Architect/Holders/SceneHolder.h
        lib/Architect/Base/Coroutine.cpp
        lib/Architect/Base/Coroutine.h
        lib/Architect/Scenes/Scenes.h
        lib/Architect/Holders/Holders.h
        lib/Architect/Base/Base.h
        lib/Architect/Objects/GameObjects/GameObjects.h
        lib/Architect/Objects/Colliders/Colliders.h
        Settings/GamePlaySceneSettings.h
        Settings/AnimationSettings.h
        lib/Architect/Objects/Colliders/RectangleCollider.h
        lib/Architect/Objects/Colliders/CircleCollider.h
        lib/Architect/Objects/Colliders/ICollider.cpp
        lib/Architect/Objects/Colliders/ICollider.h
        lib/Architect/Objects/Colliders/AbstractCollider.cpp
        lib/Architect/Objects/Colliders/AbstractCollider.h
        lib/Architect/Objects/Colliders/Collider.cpp
        lib/Architect/Objects/Colliders/Collider.h
        lib/Architect/Base/GameObject.cpp
        lib/Architect/Base/GameObject.h
) # add  target

set(SFML_DIR "C:\\AmericanDemocracySimulator\\lib\\SFML\\SFML-2.6.1\\lib\\cmake\\SFML") # link the graphic directory

target_link_libraries(AmericanDemocracySimulator sfml-graphics)

target_include_directories(AmericanDemocracySimulator PUBLIC # add other directory
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Debuger,
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Animations,
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Architect,
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Holders,
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Objects,
#        lib/Architect/Scenes
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)