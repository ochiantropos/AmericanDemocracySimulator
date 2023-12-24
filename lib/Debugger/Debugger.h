//
// Created by OchiAnthropos on 20.12.2023.
//
#ifndef AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H
#define AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H
#pragma once

#include <windows.h>   // WinApi header
#include <iostream>

namespace Game {

    class Debugger{
    public:
        enum class Color {
            DEFAULT,
            RED,
            GREEN,
            BLUE,
            YELLOW
            // Інші кольори
        };
        static void Log(const std::string& text, Color color = Color::DEFAULT);

    private:
        static void setRedColor(HANDLE hConsole);
        static void setGreenColor(HANDLE hConsole);
        static void setBlueColor(HANDLE hConsole);
        static void setYellowColor(HANDLE hConsole);
        static void resetColor(HANDLE hConsole);
        static void setCyanColor(HANDLE hConsole);
        static void setMagentaColor(HANDLE hConsole);
        static void setWhiteColor(HANDLE hConsole);
    };
}
#endif //AMERICANDEMOCRACYSIMULATOR_DEBUGGER_H
