//
// Created by OchiAnthropos on 21.12.2023.
//
#include "Architect.h"


namespace Game {
// constructors
    Scene::Scene(std::string name, const std::map<int, std::vector<GameObject *>> &layers) : Name(std::move(name)), layers(layers) {runContextCreation();}
    Scene::Scene(std::string name) :  Name(std::move(name)), layers({{0, std::vector<GameObject*>()}}){runContextCreation();}
    Scene::Scene(const std::map<int, std::vector<GameObject *>> &layers) : layers(layers) {runContextCreation();}
    Scene::Scene(std::string name, std::string contextName) :  Name(std::move(name)), ContextName(std::move(contextName)) , layers({{0, std::vector<GameObject*>()}}){runContextCreation();}

    void Scene::runContextCreation() {

    }
    void Scene::addObject(GameObject *object, int layer) {
        // Якщо лейер не вказаний або вказано неправильно
        int freeLayer = 1;
        if (layers.find(layer) == layers.end() || layer <= 0) {
            // Знайдемо перший вільний лейер або створимо новий
            while (layers.find(freeLayer) != layers.end() && freeLayer != layer) {
                ++freeLayer;
            }
        }
        layers[layer].push_back(object);
    }
    void Scene::DrawError(std::string obj) {Game::Debugger::Log("[Error][CAN\'T DRAW GAME OBJECT] in \'" + obj + "\' object has null scene Context]",Game::Debugger::Color::RED);}
} // Game