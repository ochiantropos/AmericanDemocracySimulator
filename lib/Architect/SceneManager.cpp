//
// Created by OchiAnthropos on 21.12.2023.
//
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "SceneManager.h"
#include "Scene.h"
#include "../Debugger/Debugger.h"

namespace Game {
    Scene *SceneManager::createScene() {
        auto scene = new Scene();
        scenes["none"]->scene  = scene;
        return scene;
    }

    Scene *SceneManager::createScene(std::string name) {
        auto scene = new Scene(std::move(name));
        scenes["none"]->scene  = scene;
        return scene;
    }
    Scene *SceneManager::createScene(std::string name, const std::string& contextName) {
        auto scene = new Scene(std::move(name));
        scenes[contextName]->scene  = scene;
        return scene;
    }

    void SceneManager::AddScene(){}

    void SceneManager::AddScene(Scene *scene){
        scenes[scene->ContextName]->scene = scene;
    }

    void SceneManager::setActiveScene(Scene *scene) const {
        activeScene->scene = scene;
    }

    void SceneManager::SwitchScene(const std::string& sceneName)
    {
        auto it = SceneManager::GetInstance()->scenes.find(sceneName);
        if (it != SceneManager::GetInstance()->scenes.end()) {
            SceneManager::GetInstance()->setActiveScene(it->second->scene );
            Debugger::Log("Switched to scene: " + sceneName, Debugger::Color::GREEN);
        } else {
            Debugger::Log("Scene not found: " + sceneName, Debugger::Color::RED);
        }
    }
    void SceneManager::PrintScenes() {
        Debugger::Log("Available scenes:", Debugger::Color::YELLOW);
        for (const auto& pair : SceneManager::GetInstance()->scenes) {
            Debugger::Log(pair.first, Debugger::Color::GREEN);
        }
    }

    SceneManager *SceneManager::GetInstance() {
        if(singleton_==nullptr){
            singleton_ = new SceneManager();
        }
        return singleton_;
    }
}