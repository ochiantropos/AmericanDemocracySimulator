//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENE_H
#define AMERICANDEMOCRACYSIMULATOR_SCENE_H
#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <filesystem>
#include "GameObject.h"

namespace Game {

    class GameObject;

    class Scene {
    private:
        std::map<int, std::vector<GameObject*>> layers;
        sf::Clock clock;

    public:
        sf::RenderWindow window;

        Scene() = default;
        explicit Scene(std::string name, const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(std::string name);
        explicit Scene(std::string name, std::string contextName);
        void addObject(GameObject* object, int layer);

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
