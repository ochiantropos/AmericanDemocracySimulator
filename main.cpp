#include <SFML/Graphics.hpp>
#include "GamePlayScene.h"
#include "lib/Architect/SceneManager.h"
#include "lib/Debugger/Debugger.h"
#include <vector>

using namespace std;
using namespace Game;
//Declare ini
const int screenWidth = 900;
const int screenHeight = 560;
float deltaTime = 0;
// statement values
bool isKeyPressed = false;
bool isRightMouseButtonPressed = false;
// contexts
sf::RenderWindow windowContext(sf::VideoMode(screenWidth, screenHeight), "Main");
std::map<std::string, sf::RenderWindow*> m_screens = {
        { "Main",&windowContext }
};
//main scene manager
SceneManager* SceneManager::singleton_= nullptr;

int y_size = windowContext.getSize().y / 80;
int x_size = windowContext.getSize().x / 80;

// funck declatation
void DebugInspector(map<int, vector<GameObject *>> objects, int max_in_layer);
void DrawActiveScene(map<int, vector<GameObject *>> &objects);
void StartGameCicle(SceneManager *sceneManager, map<int, vector<GameObject *>> &objects);
void EventLoopDispatch(SceneManager *sceneManager);
map<int, vector<GameObject*>> PoolSceneManager(SceneManager *sceneManager);
// scenes creation
GamePlayScene *scene = new GamePlayScene( new Scene("MainScene", "Main"), (int)windowContext.getSize().y, (int)windowContext.getSize().x);

int main()
{
    auto sceneManager = SceneManager::GetInstance(); // get scene manager instance
    auto objects = PoolSceneManager(sceneManager); // pooling the scenes and objects
    StartGameCicle(sceneManager,objects);
    return 0;
}

void StartGameCicle(SceneManager *sceneManager, map<int, vector<GameObject *>> &objects) {
    while (windowContext.isOpen())
    {
        EventLoopDispatch(sceneManager);
        objects = sceneManager->activeScene->scene->getObjects();
        windowContext.clear(sf::Color::White);
        DrawActiveScene(objects);
        windowContext.display();
        sceneManager->activeScene->Next();
    }
}

void EventLoopDispatch(SceneManager *sceneManager) {
    sf::Event event {};
    while (windowContext.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            windowContext.close();
        else {
            if (event.type == sf::Event::KeyPressed) {  // Обробка події натискання клавіші

                if (event.key.code == sf::Keyboard::Space) { // Виконати дії під час натискання клавіші Space
                    isKeyPressed = true;

                }
            } else if (event.type == sf::Event::KeyReleased) { // Виконати дії під час відпускання клавіші Space
                if (event.key.code == sf::Keyboard::Space) { // Обробка події відпускання клавіші
                    isKeyPressed = false;

                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) { // Виконати дії під час натискання правої кнопки миші

                    if (isRightMouseButtonPressed) // pressed
                        sceneManager->activeScene->OnClicked();
                    else   // first press
                        sceneManager->activeScene->OnClickedStart();

                    isRightMouseButtonPressed = true;
                }
            } else if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Right) { // Виконати дії під час відпускання правої кнопки миші
                    sceneManager->activeScene->OnClickedEnd();
                    isRightMouseButtonPressed = false;
                }
            }
        }
    }
}


map<int, vector<GameObject*>> PoolSceneManager(SceneManager *sceneManager) {

    sceneManager->AddScene(scene);
    SceneManager::PrintScenes();
    SceneManager::SwitchScene("Main");
    sceneManager->activeScene->scene->getObjects();
    sceneManager->activeScene->Start();
    auto objects = sceneManager->activeScene->scene->getObjects();
    DebugInspector(objects, 2);
    return objects;
}

void DrawActiveScene(map<int, vector<GameObject *>> &objects) {
    for (auto& layer : objects) {
        auto& gameObjects = layer.second;
        for (auto* gameObject : gameObjects)
        {
            auto draw_objects =  gameObject->holder.objects;
            gameObject->UpdateDrawObjects();
            for (const auto& sprite : draw_objects)
                windowContext.draw(sprite.second);
        }
    }
}

void DebugInspector(map<int, vector<GameObject *>> objects, int max_in_layer = 5){
    for (auto& layer : objects) {

        std::vector<GameObject*>& gameObjects = layer.second;

        int count = 0;
        std::string tabs;
        for (int i = 1; i <= layer.first; i++) tabs.append("\t");
        auto layerIndexName = std::string(" ["  + to_string(layer.first) + "] ");
        GameObject *last;
        for (auto* gameObject : gameObjects) {

            if (count < max_in_layer)
                Debugger::Log( layerIndexName + tabs = " "  + std::string(to_string(count)) + "-" + gameObject->gameObjectName , Game::Debugger::Color::BLUE);
            else if (count == max_in_layer)
                Debugger::Log( tabs + std::string(" ..... "),  Game::Debugger::Color::BLUE);
            last = gameObject;
            count++;
        }
        if (count >= max_in_layer) Debugger::Log( layerIndexName + tabs = " "  + std::string(to_string(count-1)) + "-" + last->gameObjectName , Game::Debugger::Color::BLUE);
    }
}