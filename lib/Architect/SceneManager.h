//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#define AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#include <iostream>
#include "Scene.h"

namespace Game {

    class SceneManager {

    public:
        static SceneManager* singleton_;
        static void SwitchScene(const std::string& sceneName);
        static void PrintScenes();

         Scene *createScene();
         Scene *createScene(std::string name);
         Scene *createScene(std::string name, const std::string& contextName);
         void setActiveScene(Scene *scene);
         void AddScene(Scene *scene);
         void AddScene();

        Scene *activeScene = nullptr;

         std::map<std::string, sf::RenderWindow*>  constexts;
         std::map<std::string, Scene*> scenes;

        SceneManager(SceneManager &other) = delete;
        static SceneManager *GetInstance();

    protected:
        SceneManager() = default;

    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
