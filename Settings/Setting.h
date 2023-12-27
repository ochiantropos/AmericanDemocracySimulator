//
// Created by OchiAnthropos on 27.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SETTING_H
#define AMERICANDEMOCRACYSIMULATOR_SETTING_H
#pragma once
#include <string>
#include <unistd.h>
#include <filesystem>
#include <iostream>

class Setting{
public:
    std::string game_folder = R"(C:\AmericanDemocracySimulator\)"; // by default
    // Скомпонуємо повний шлях до файлу ground_sheet.png
    std::filesystem::path currentPath;
    [[nodiscard]] std::string GetPath(const std::string& path) const{

//        std::cout << (std::filesystem::path(game_folder) / path).generic_string() << std::endl;
        return (std::filesystem::path(game_folder) / path).generic_string();

    }
    Setting() {
        currentPath = std::filesystem::current_path();
        game_folder = currentPath.generic_string();
    };
};

#endif //AMERICANDEMOCRACYSIMULATOR_SETTING_H
