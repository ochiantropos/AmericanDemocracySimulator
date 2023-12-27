//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H
#define AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H
#pragma once
#include "Base/Base.h"
#include "../Animations/Animation.h"
#include "../Debugger/Debugger.h"

namespace Game {
    class GameObject;
    class Scene;
    class SceneHolder;
    class SceneManager;

    enum class GameState{
        Default,
        Play,
        Preview,
        Start,
        Pause,
        Menu
        // Інші кольори
    };


    class Scene {
    private:
        std::map<int, std::vector<GameObject*>> layers;
        sf::Clock clock;
    public:

        GameState currentState = GameState::Preview;
        sf::RenderWindow window;
        Scene() = default;
        explicit Scene(std::string name, const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(const std::map<int, std::vector<GameObject *>> &layers);
        explicit Scene(std::string name);
        explicit Scene(std::string name, std::string contextName);
        void addObject(GameObject *object, int layer);
        void delObject(GameObject *object, int layer);

        std::map<int, std::vector<GameObject*>>& getObjects() {return layers;}
// ------      values     ------
        std::string Name;
        std::string ContextName;
        int layerCount = 0;
        void runContextCreation();
        static void DrawError(std::string obj);
        sf::RenderWindow *windowContext{};


        void Clear();
    };

    class SceneManager {
    public:
        static SceneManager *singleton_;
         void SwitchScene(const std::string &sceneName);
        static void PrintScenes();
        static Scene *createScene();
        static Scene *createScene(std::string name);
        static Scene *createScene(std::string name, const std::string &contextName);
         int CallToSwitch;
         std::string CallToSwitchName;

        void AddScene(SceneHolder *sceneHolder);
        void AddScene(SceneHolder sceneHolder);
        SceneHolder *activeScene = nullptr;
        std::map<std::string, sf::RenderWindow *> constexts;
        std::map<std::string, SceneHolder *> scenes;
        SceneManager(SceneManager &other) = delete;
        static SceneManager *GetInstance();


        static void SwitchSceneImidiatly(const std::string &sceneName);

    protected:
        SceneManager() = default;
        void setActiveScene(SceneHolder *sceneHolder);
    };

    class GameObject : public AbstractGameObject{
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        std::vector<Game::GameState> allowedRenderStatus = {};
        float width = 0;
        float height = 0;
        float x_position = 0;
        float y_position = 0;
        bool deletable = false;
        GameObject();
        virtual ~GameObject() = default;
        explicit GameObject(Scene *context) {currentContext = context;}
        void update(float deltaTime) override {};
        void draw(sf::RenderWindow& window) override{}
        std::map<std::string, sf::Sprite>& getObjects() {return holder.objects;}
        std::string gameObjectName = "GameObject";
        virtual void  UpdateDrawObjects() = 0;
        virtual void SetPosition(float x, float y ) {};
        virtual void MovePosition(float x, float y)  {};
        Scene *currentContext = nullptr;
        Animation *baseAnimation;
        bool CastRenderAvailable(){
            if (currentContext == nullptr){
                Scene::DrawError(gameObjectName);
                return false;
            }
            auto it = std::find(allowedRenderStatus.begin(), allowedRenderStatus.end(), currentContext->currentState);
            if (it != allowedRenderStatus.end()) {
                return true;
            } else {
                return false;
            }
        }
        static void AllowAll(GameObject *obj) {
            obj->allowedRenderStatus.push_back(GameState::Start);
            obj->allowedRenderStatus.push_back(GameState::Play);
            obj->allowedRenderStatus.push_back(GameState::Menu);
            obj->allowedRenderStatus.push_back(GameState::Pause);
        }
        static void Allow(GameObject *obj, GameState state) { obj->allowedRenderStatus.push_back(state); }
        static void Allow(GameObject *obj,const std::vector<GameState>& states) { for (auto state : states) obj->allowedRenderStatus.push_back(state); }
        void AllowAll() {
            allowedRenderStatus.push_back(GameState::Start);
            allowedRenderStatus.push_back(GameState::Play);
            allowedRenderStatus.push_back(GameState::Menu);
            allowedRenderStatus.push_back(GameState::Pause);
        }

        void Allow(const std::vector<GameState>& states) { for (auto state : states) allowedRenderStatus.push_back(state); }
        void Allow(GameState state) { allowedRenderStatus.push_back(state); }
    };
}


#endif //AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H
