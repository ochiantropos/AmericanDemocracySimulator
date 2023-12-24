//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_COROUTINE_H
#define AMERICANDEMOCRACYSIMULATOR_COROUTINE_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <random>

namespace Game {

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

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_COROUTINE_H
