//
// Created by OchiAnthropos on 23.12.2023.
//

#include "SceneHolder.h"

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
} // Game