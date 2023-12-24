//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENE_H
#define AMERICANDEMOCRACYSIMULATOR_SCENE_H
#pragma once
#include <map>
#include <filesystem>
#include "../Base/Base.h"

namespace Game {


    class Scene {
    private:
        sf::Clock clock;

    public:
        sf::RenderWindow window;
        std::map<int, std::vector<GameObject*>> layers;

        explicit Scene(std::string name, const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(std::string name);
        explicit Scene(std::string name, std::string contextName);
//        void AddObject(GameObject * object, int layer);
        void AddObject(GameObject *object, int layer);

        std::map<int, std::vector<GameObject*>>& getObjects() {return layers;}

// ------      values     ------
        std::string Name;
        std::string ContextName;

        int layerCount = 0;

        void runContextCreation();

        sf::RenderWindow *windowContext{};

    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_SCENE_H
