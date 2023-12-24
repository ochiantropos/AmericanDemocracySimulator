//
// Created by OchiAnthropos on 24.12.2023.
//

#include "Coroutine.h"

namespace Game {

    void Coroutine::Delta(float deltaTime) {
        processedTime += deltaTime;
        if (processedTime > borderTime) {
            processedStatus = true;
            processedTime -= borderTime;
        } else {
            processedStatus = false;
        }
    }

    void Coroutine::Continue(float deltaTime) {
        Delta(deltaTime);
        if (processedStatus) {
            process();
            ChangeCurrentBorder();
        }
    }

    void Coroutine::Continue() {
        if (processedStatus) {
            process();
            ChangeCurrentBorder();
        }
    }

    void Coroutine::ChangeCurrentBorder() {
        if (borderChangeableStatus) {
            std::random_device rd;  // Створення об'єкта для отримання випадкових чисел
            std::mt19937 gen(rd()); // Генератор випадкових чисел на основі rd()
            std::uniform_int_distribution<int> distribution((int) (borderTimeMin * 1000), (int) (borderTimeMax *
                                                                                                 1000)); // Встановлення діапазону для випадкового числа від 0 до 100 (змініть за потребою)
            int x = distribution(gen);
            borderTime = (float) (x) / 1000;
        }
    }

    Coroutine::Coroutine(std::function<void()> process) : process(std::move(process)) {}

    Coroutine::Coroutine(std::function<void()> process, float processedTime, float borderTime,
                         bool processedStatus) : process(std::move(process)), processedTime(processedTime),
                                                 borderTime(borderTime),
                                                 processedStatus(processedStatus) {}

    Coroutine::Coroutine(std::function<void()> process, float borderTime) : process(std::move(process)),
                                                                            borderTime(borderTime) {}

    Coroutine::Coroutine(std::function<void()> process, float min, float max) {
        this->process = std::move(process);
        borderChangeableStatus = true;
        borderTime = min;
        borderTimeMin = min;
        borderTimeMax = max;
    }

    Coroutine::Coroutine(std::function<void()> process, float min, float max, float start) {
        this->process = std::move(process);
        borderChangeableStatus = true;
        borderTime = start;
        borderTimeMin = min;
        borderTimeMax = max;
    }
} // Game