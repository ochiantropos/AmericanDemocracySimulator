//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#define AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
#include <iostream>
#include "Scene.h"
#include "Base/SceneHolder.h"

namespace Game {

    class SceneManager {


    public:
        static SceneManager *singleton_;

        static void SwitchScene(const std::string &sceneName);

        static void PrintScenes();

        static Scene *createScene();

        static Scene *createScene(std::string name);

        static Scene *createScene(std::string name, const std::string &contextName);

        void setActiveScene(Scene *scene) const;


        void AddScene();

        SceneHolder *activeScene = nullptr;

        std::map<std::string, sf::RenderWindow *> constexts;
        std::map<std::string, SceneHolder *> scenes;

        SceneManager(SceneManager &other) = delete;

        static SceneManager *GetInstance();

        void AddScene(SceneHolder *sceneHolder);

        void AddScene(SceneHolder sceneHolder);

    protected:
        SceneManager() = default;

        void setActiveScene(SceneHolder *sceneHolder);

        void setActiveScene(SceneHolder sceneHolder);
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_SCENEMANAGER_H
