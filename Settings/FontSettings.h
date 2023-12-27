//
// Created by OchiAnthropos on 27.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_FONTSETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_FONTSETTINGS_H
#pragma once
#include "Setting.h"

namespace Game {
    class FontSettings : public Setting {
        friend class GamePlayScene;
    public:
        std::string baseFont = R"(fonts\Arial.ttf)";
        std::string informationFont = R"(fonts\NotoSerif\NotoSerif-Regular.ttf)";
        std::string informationHeaderFont = R"(fonts\JosefinSans\JosefinSans-Regular.ttf)";
    };
}
#endif //AMERICANDEMOCRACYSIMULATOR_FONTSETTINGS_H
