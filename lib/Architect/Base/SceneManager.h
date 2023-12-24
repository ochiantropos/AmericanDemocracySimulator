//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#define AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#include <iostream>
#include "../Holders/Holders.h"

namespace Game {

    class SceneManager {

    public:
        static SceneManager* singleton_;
        static void SwitchScene(const std::string& sceneName);
        static void PrintScenes();

        Scene *createScene();
        Scene *createScene(std::string name);
        Scene *createScene(std::string name, const std::string& contextName);
         void setActiveScene(SceneHolder *scene);
         void AddScene(SceneHolder *scene);
         void AddScene();

        SceneHolder *activeScene = nullptr;

         std::map<std::string, sf::RenderWindow*>  constexts;
         std::map<std::string, SceneHolder*> scenes;

        SceneManager(SceneManager &other) = delete;
        static SceneManager *GetInstance();

    protected:
        SceneManager() = default;

    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
