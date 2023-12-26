cmake_minimum_required(VERSION 3.17)
project(AmericanDemocracySimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(AmericanDemocracySimulator
        main.cpp
        lib/Debugger/Debugger.cpp
        lib/Debugger/Debugger.h

        Dependency.h

        lib/Scenes/GamePlayScene.cpp
        lib/Scenes/GamePlayScene.h

        lib/Objects/Objects.h
        lib/Objects/Boom.cpp
        lib/Objects/DeadShip.cpp
        lib/Objects/Ground.cpp
        lib/Objects/Point.cpp
        lib/Objects/Ship.cpp
        lib/Objects/ShipDieAnimated.cpp
        lib/Objects/WaterPool.cpp


        lib/Architect/Architect.h
        lib/Architect/GameObject.cpp
        lib/Architect/Scene.cpp
        lib/Architect/SceneManager.cpp

        lib/Architect/Base/Base.h
        lib/Architect/Base/DrawableHolder.cpp
        lib/Architect/Base/IColliderCompare.cpp
        lib/Architect/Base/SceneHolder.cpp
        lib/Architect/Base/RectangleCollider.cpp
        lib/Architect/Base/Coroutine.cpp
        lib/Architect/Base/Collider.cpp
        lib/Architect/Base/CircleCollider.cpp
        lib/Architect/Base/AbstractColliderType.cpp

        lib/Animations/Animation.h
        lib/Animations/Animation.cpp
        lib/Animations/WaterAnimation.cpp
        lib/Animations/PointAnimation.cpp
        lib/Animations/GroundAnimation.cpp
        lib/Animations/DeadAnimation.cpp
        lib/Animations/BoomAnimation.cpp
        lib/UI/UI.h
) # add  target

set(SFML_DIR "C:\\AmericanDemocracySimulator\\SFML\\lib\\cmake\\SFML") # link the graphic directory

target_link_libraries(AmericanDemocracySimulator sfml-graphics)

target_include_directories(AmericanDemocracySimulator PUBLIC # add other directory
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/include,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Debuger,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Animations,

        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Architect,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Architect/Base,

        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Holders,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Objects,
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/Scenes
)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)