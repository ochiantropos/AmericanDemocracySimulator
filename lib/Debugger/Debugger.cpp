//
// Created by OchiAnthropos on 20.12.2023.
//

#include <iostream>
#include "Debugger.h"

namespace Game {

    void Debugger::Log(const std::string &text, Color color) {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // you can loop k higher to see more color choices
        switch (color) {
            case Color::RED:
                setRedColor(hConsole);
                break;
            case Color::GREEN:
                setGreenColor(hConsole);
                break;
            case Color::BLUE:
                setBlueColor(hConsole);
                break;
            case Color::YELLOW:
                setYellowColor(hConsole);
                break;
            case Color::DEFAULT:
            default:
                resetColor(hConsole);
                break;
        }
        std::cout << text << std::endl;
        resetColor(hConsole);
    }
    void Debugger::setRedColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Червоний текст
    }
    void Debugger::setGreenColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Зелений текст
    }
    void Debugger::setBlueColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Синій текст
    }
    void Debugger::setYellowColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Жовтий текст
    }
    void Debugger::setCyanColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Блакитний текст
    }
    void Debugger::setMagentaColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Пурпурний текст
    }
    void Debugger::setWhiteColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Білий текст
    }


    void Debugger::resetColor(HANDLE hConsole) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    }
}