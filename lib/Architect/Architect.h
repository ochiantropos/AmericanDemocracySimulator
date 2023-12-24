//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H
#define AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H

namespace Game {
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
        void addObject(GameObject *object, int layer);
        std::map<int, std::vector<GameObject*>>& getObjects() {return layers;}
// ------      values     ------
        std::string Name;
        std::string ContextName;
        int layerCount = 0;
        void runContextCreation();
        sf::RenderWindow *windowContext{};
    };

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







}


#endif //AMERICANDEMOCRACYSIMULATOR_ARCHITECT_H
