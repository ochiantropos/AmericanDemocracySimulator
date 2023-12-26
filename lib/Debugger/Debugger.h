//
// Created by OchiAnthropos on 20.12.2023.
//
#ifndef AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H
#define AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H

#include <windows.h>   // WinApi header
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#pragma once
#include "../Architect/Architect.h"

namespace Game {

    class GameObject;

    class Debugger{
    public:
        enum class Color {
            DEFAULT,
            RED,
            GREEN,
            BLUE,
            YELLOW
        };
        static void Log(const std::string& text, Color color = Color::DEFAULT);
        static void DebugInspector(std::map<int, std::vector<GameObject *>> objects, int max_in_layer);
    private:
        static void setRedColor(HANDLE hConsole);
        static void setGreenColor(HANDLE hConsole);
        static void setBlueColor(HANDLE hConsole);
        static void setYellowColor(HANDLE hConsole);
        static void resetColor(HANDLE hConsole);
        static void setCyanColor(HANDLE hConsole);
        static void setMagentaColor(HANDLE hConsole);
        static void setWhiteColor(HANDLE hConsole);

        static void LogThread(int clearTime);

    };
}
#endif //AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H
