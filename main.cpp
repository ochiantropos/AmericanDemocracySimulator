#include <iostream>
#include <SFML/Graphics.hpp>
#include "lib/Game.h"
#include "lib/Scenes/GamePlayScene.h"
#include <vector>

using namespace std;
using namespace Game;
//Declare ini
const int screenWidth = 900;
const int screenHeight = 560;
float deltaTime = 0;

void DebugInspector(map<int, vector<GameObject *>> objects);


sf::RenderWindow windowContext(sf::VideoMode(screenWidth,  screenHeight), "Main");
std::map<std::string, sf::RenderWindow*> m_screens = {
        { "Main",&windowContext }
};
SceneManager* SceneManager::singleton_= nullptr;

int y_size = windowContext.getSize().y / 80;
int x_size = windowContext.getSize().x / 80;

int main()
{

    sf::Clock clock;
    GamePlayScene scene = GamePlayScene( new Scene("MainScene", "Main"), y_size, x_size);

    auto sceneManager = SceneManager::GetInstance();
    sceneManager->AddScene(scene.scene);

    SceneManager::PrintScenes();
    SceneManager::SwitchScene("Main");




    // log all
    sceneManager->activeScene->getObjects();
    auto objects = sceneManager->activeScene->getObjects();
    DebugInspector(objects);
    while (windowContext.isOpen())
    {
        sf::Event event {};

        while (windowContext.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                windowContext.close();
        }
        objects = sceneManager->activeScene->getObjects();
        windowContext.clear(sf::Color::White);

        for (auto& layer : objects) {
            auto& gameObjects = layer.second;
            for (auto* gameObject : gameObjects)
            {
                auto draw_objects =  gameObject->holder.objects;
                gameObject->UpdateDrawObjects();
                for (const auto& sprite : draw_objects)
                {
                    windowContext.draw(sprite.second);
                }
            }
        }

        windowContext.display();
    }
    return 0;
}


void DebugInspector(map<int, vector<GameObject *>> objects){
    for (auto& layer : objects) {
        std::vector<GameObject*>& gameObjects = layer.second;
        for (auto* gameObject : gameObjects) {
            auto layerIndexName = std::string(" ["  + to_string(layer.first) + "] ");
            std::string tabs;
            for (int i = 1; i <= layer.first; i++) tabs.append("\t");
            Debugger::Log(  layerIndexName + tabs + gameObject->gameObjectName , Game::Debugger::Color::BLUE);
        }
    }
}