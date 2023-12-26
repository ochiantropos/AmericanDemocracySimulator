//
// Created by OchiAnthropos on 24.12.2023.
//

#include "Base.h"


namespace Game {
    void SceneHolder::AsyncRunState() {
        if (fixedUpdateRunStatus) FixedUpdate();
        if (updateRunStatus) Update();
    }
    void SceneHolder::deleteCoroutineFunk(const std::string &name) {
        auto it = void_stack.find(name);
        if (it != void_stack.end()) {
            delete it->second;
            void_stack.erase(it);
        }
    }

    void SceneHolder::addCCoroutineFunk(Coroutine *coroutine, const std::string &name) {
        void_stack[name] = coroutine;
    }
    void SceneHolder::addCCoroutineFunk(const std::string &name, Coroutine *coroutine) { addCCoroutineFunk(coroutine, name); }

    void SceneHolder::addCCoroutineFunk(const std::function<void()> &runtime, const std::string &name, float time) {
    }

    SceneHolder::SceneHolder(Scene *_scene, int _y_size, int _x_size) : scene(_scene), x_size(_x_size), y_size(_y_size) {}

    SceneHolder::SceneHolder(Scene *_scene, sf::RenderWindow *context, int _y_size, int _x_size) : scene(_scene), x_size(_x_size), y_size(_y_size)  {}

    SceneHolder::SceneHolder() = default;
} // Game