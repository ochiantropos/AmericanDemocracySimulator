#define SFML_ENABLED
#ifdef SFML_ENABLED
#include <SFML/Audio/Music.hpp>
#include "lib/Architect/Architect.h"
using namespace std;
using namespace Game;
#include "GamePlayScene.h"
//Declare ini
GamePlayScenesSetting setting = *new GamePlayScenesSetting();
const int screenWidth = setting.screenWidth;
const int screenHeight = setting.screenHeight;
float deltaTime = 0;
// statement values
bool isKeyPressed = false;
bool isRightMouseButtonPressed = false;
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
GamePlayScene *scene = new GamePlayScene( new Scene("MainScene", "Main"), &windowContext, (int)windowContext.getSize().y, (int)windowContext.getSize().x);
//good-morning-vietnam.mp3
#else
//#include "lib/Debugger/Debugger.h"
//using namespace std;
//using namespace Game;
#endif
int main()
{
    sf::Music music;
    if (!music.openFromFile(setting.ms)) {} else {}
    try {
        music.setLoop(true);
        music.play();
        auto sceneManager = SceneManager::GetInstance(); // get scene manager instance
        auto objects = PoolSceneManager(sceneManager); // pooling the scenes and objects
        StartGameCicle(sceneManager,objects);

    } catch (exception e){


    }


    return 0;
}
#ifdef SFML_ENABLED
void StartGameCicle(SceneManager *sceneManager, map<int, vector<GameObject *>> &objects)
{
    while (windowContext.isOpen())
    {
        objects = sceneManager->activeScene->scene->getObjects();
        EventLoopDispatch(sceneManager);
        windowContext.clear(sf::Color::Black);
        DrawActiveScene(objects);
        sceneManager->activeScene->DrawUI();
        windowContext.display();
        sceneManager->activeScene->Next();
    }
}
void EventLoopDispatch(SceneManager *sceneManager)
{
    sf::Event event {};
    while (windowContext.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            windowContext.close();
        else
        {
            if (event.type == sf::Event::KeyPressed) {  // Обробка події натискання клавіші
                if (event.key.code == sf::Keyboard::Space) {// Виконати дії під час натискання клавіші Space
                    isKeyPressed = true;
                }
            }
            else if (event.type == sf::Event::KeyReleased) { // Виконати дії під час відпускання клавіші Space
                if (event.key.code == sf::Keyboard::Space)  // Обробка події відпускання клавіші
                    isKeyPressed = false;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button ==
                    sf::Mouse::Right) { // Виконати дії під час натискання правої кнопки миші

                    isRightMouseButtonPressed = true;
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (isRightMouseButtonPressed) // pressed
                    sceneManager->activeScene->OnClicked();
                else   // first press
                    sceneManager->activeScene->OnClickedStart();
                isRightMouseButtonPressed = true;
            } else {
                if (isRightMouseButtonPressed) {
                    sceneManager->activeScene->OnClickedEnd();
                }
                isRightMouseButtonPressed = false;
            }
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Right){ // Виконати дії під час відпускання правої кнопки миші
                    sceneManager->activeScene->OnClickedEnd();
                }
        }
    }
}
map<int, vector<GameObject*>> PoolSceneManager(SceneManager *sceneManager)
{
    sceneManager->AddScene(scene);
    SceneManager::PrintScenes();
    SceneManager::SwitchSceneImidiatly("MainScene");

    sceneManager->activeScene->scene->getObjects();
    sceneManager->activeScene->Start();
    auto objects = sceneManager->activeScene->scene->getObjects();
    Debugger::DebugInspector(objects, 2);
    return objects;
}
void DrawActiveScene(map<int, vector<GameObject *>> &objects)
{
    for (auto& layer : objects)
    {
        auto& gameObjects = layer.second;
        for (auto* gameObject : gameObjects)
        {
            if (!gameObject->CastRenderAvailable()) continue;
            auto draw_objects =  gameObject->holder.objects;
            gameObject->UpdateDrawObjects();
            for (const auto& sprite : draw_objects)
            {
                windowContext.draw(sprite.second);
            }
        }
    }
    // UI
}
#endif