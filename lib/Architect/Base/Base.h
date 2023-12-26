//
// Created by OchiAnthropos on 25.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_BASE_H
#define AMERICANDEMOCRACYSIMULATOR_BASE_H
#pragma once
#include "../../../Dependency.h"
namespace Game {

    class Scene;

    class AbstractColliderType {
    public:
        AbstractColliderType();

        sf::Vector2f center = {0, 0};
    };
    template<typename TColliderType>
    class Collider {

    private:
        AbstractColliderType collider{};
    public:
        TColliderType colliderType{};

        explicit Collider(TColliderType coll);

        bool CompareCollider(Collider collider2) {
            return true;
        }
    };

    class DrawableHolder {
    public:
        std::map<std::string,sf::Sprite> objects;
        DrawableHolder();
        explicit DrawableHolder( const std::map<std::string,sf::Sprite>&  vectorData);
        void AddDrawable(  sf::Sprite object, const std::string& name);
        void AddDrawable(  sf::Sprite object);
        void DeleteDrawable( std::string &name);
        void DeleteDrawable(  const sf::Sprite& object, const std::string& name);
        void addObject( const std::string& key, sf::Sprite object);
        void removeObject(const std::string &key);
    };


    class Coroutine {
    protected:
        std::function<void()> process;
        float processedTime = 0.0f;
        float borderTime = 0.2f;
        float borderTimeMax = 0.2f;
        float borderTimeMin = 0.1f;
        bool borderChangeableStatus = false;
        bool processedStatus = false;
        void ChangeCurrentBorder();
    public:
        explicit Coroutine( std::function<void()> process);
        explicit Coroutine( std::function<void()> process, float borderTime);
        explicit Coroutine( std::function<void()> process, float min, float max);
        explicit Coroutine( std::function<void()> process, float min, float max, float start);
        explicit Coroutine( std::function<void()> process, float processedTime, float borderTime, bool processedStatus);
        void Delta(float deltaTime);
        void Continue();
        void Continue(float deltaTime);
    };

    class HolderableObject{
    public:
        DrawableHolder holder = DrawableHolder();
    };
    class  AbstractGameObject : public  HolderableObject{
    public:
        virtual void update(float deltaTime) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
    };


    class SceneHolder {
    private:
        float frameFixedDeltaTime = 0.00f;
        void AsyncRunState();
        void Main(){
            deltaTime = clock.restart().asSeconds();
            liveTime += deltaTime;
            updateRunStatus = true;

            if ( frameFixedDeltaTime <= fixedDeltaTime ){
                fixedUpdateRunStatus = true;
                frameFixedDeltaTime -= fixedDeltaTime;
            } else {
                frameFixedDeltaTime += deltaTime;
                fixedUpdateRunStatus = false;
            }
            AsyncRunState();
            for (auto Coroutine : void_stack) Coroutine.second->Continue(deltaTime);
        }

    protected:
        // fun, current time, border
        SceneHolder(Scene *_scene, int _y_size, int _x_size);
        SceneHolder(Scene *_scene,sf::RenderWindow *context, int _y_size, int _x_size);

        bool updateRunStatus = true;
        bool fixedUpdateRunStatus = false;
        int x_size = 0;
        int y_size = 0;
        std::map<std::string, Game::Coroutine*> void_stack{};

        sf::Clock clock;
        sf::Vector2i mousePosition = {0,0};

        float liveTime = 0;
        float fixedDeltaTime = 0.02f;

        float deltaTime = 0;

    public:
        SceneHolder();

        virtual void Update() {};
        virtual void FixedUpdate() {};
        virtual void Start() {};

        virtual void OnClicked() {};
        virtual void OnClickedStart() {};
        virtual void OnClickedEnd() {};

        virtual void CreateUI() {};
        virtual void CheckUICollision() {};
        virtual void DrawUI() {};

        void deleteCoroutineFunk(const std::string& name);

        virtual void Next() {
            Main();
        };

        void addCCoroutineFunk(const std::function<void()> &runtime, const std::string &name, float time);

        void addCCoroutineFunk(Coroutine *coroutine, const std::string &name);

        void addCCoroutineFunk(const std::string &name, Coroutine *coroutine);
        Scene *scene{};

    };


    class IColliderCompare {
//        bool CheckCollision(CircleCollider collider1, CircleCollider collider2);
//
//        bool CheckCollision(CircleCollider collider1, RectangleCollider collider2);
//
//        bool CheckCollision(RectangleCollider collider1, CircleCollider collider2);
//
//        bool CheckCollision(RectangleCollider collider1, RectangleCollider collider2);
    };


    class CircleCollider : AbstractColliderType {

    };

    class RectangleCollider : AbstractColliderType {

    };
}
#endif //AMERICANDEMOCRACYSIMULATOR_BASE_H
