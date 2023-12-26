//
// Created by OchiAnthropos on 20.12.2023.
//



#include "Debugger.h"

namespace Game {
    std::vector<int> messageIndices; // Вектор для зберігання індексів рядків
    void Debugger::Log(const std::string &text, Color color) {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        int lastMessageIndex = csbi.dwCursorPosition.Y;
        messageIndices.push_back(lastMessageIndex);
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

    void Debugger::LogThread(int clearTime){
        std::this_thread::sleep_for(std::chrono::milliseconds ( (int)clearTime ));
        system("cls");
        Debugger::Log( "system(\"cls\"); " + std::string (std::to_string(clearTime)), Color::RED);
    }

    void Debugger::DebugInspector(std::map<int, std::vector<GameObject *>> objects, int max_in_layer = 5){
        for (auto& layer : objects) {
            std::vector<GameObject*>& gameObjects = layer.second;
            int count = 0;
            std::string tabs;
            for (int i = 1; i <= layer.first; i++) tabs.append("\t");
            auto layerIndexName = std::string(" ["  + std::to_string(layer.first) + "] ");
            GameObject *last;
            for (auto* gameObject : gameObjects) {
                if (!gameObject->CastRenderAvailable()) continue;
                if (count < max_in_layer)
                    Debugger::Log( layerIndexName + tabs + " "  + std::string(std::to_string(count)) + "-" + gameObject->gameObjectName , Game::Debugger::Color::BLUE);
                else if (count == max_in_layer)

                    Debugger::Log( tabs + std::string(" ..... "),  Game::Debugger::Color::BLUE);
                last = gameObject;
                count++;
            }
            if (count >= max_in_layer)
                Debugger::Log( layerIndexName + tabs + " "  + std::string(std::to_string(count)) + "-" + last->gameObjectName , Game::Debugger::Color::BLUE);
        }
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