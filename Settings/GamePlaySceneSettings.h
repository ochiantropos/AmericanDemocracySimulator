//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
#pragma once

#include <string>
#include "AnimationSettings.h"

namespace Game {
    class GamePlayScenesSetting {
        friend class GamePlayScene;

    private:

        const AnimationSettings animationSettings = AnimationSettings();

        const std::string ship_type_one_path = R"(C:\AmericanDemocracySimulator\textures\ship_type_second.png)";
        const std::string ship_type_one_path_die;
        const float ship_type_one_speed = 5.0f;

        const float ship_type_one_width = 100.0f;
        const float ship_type_one_height = 30.0f;

        const std::string ship_type_two_path = R"(C:\AmericanDemocracySimulator\textures\ship_type_second.png)";
        const std::string ship_type_two_path_die;
        const float ship_type_two_speed = 5.0f;
        const float ship_type_two_width = 130.0f;
        const float ship_type_two_height = 35.0f;

        const std::string ship_type_tree_path;
        const std::string ship_type_tree_path_die;
        const float ship_type_tree_speed = 5.0f;

        const float panelUISizeX= 200;
        const float panelUISizeY = 250;

        const int panelUIPositionXDefault = 0;
        const int panelUIPositionYDefault  = 0;

        const float panelUIPositionXCenter = screenWidth/2 - panelUISizeX/2;
        const float panelUIPositionYCenter  = screenHeight/2 - panelUISizeY/2;


        std::vector<std::string> information =
                {                 "Voytusik (ochiantropos) Ivan\n", // 0

                                  "Co-Founder & Lead Unity Developer at Wildery\n", // 1
                                  "  Location: Kyiv, Ukraine\n", // 2
                                  std::string("")+
                                            "    GitHub Profile https://github.com/ochiantropos\n"+
                                            "    Telegram https://t.me/Vanyenot\n"+
                                            "    Steam Community https://steamcommunity.com/profiles/7656\n", // 3

                                  "Professional Experience\n", // 4
                                  "\tWildery\n", //5

                                  "\t  Lead Unity Developer\n", //6

                                  std::string("")+
                                  "\t\t -April 2022 - Present (1 year, 9 months)\n"+
                                  "\t\tRemote work focused on team leadership and software development  \n"+
                                  "\t\tfor Android and Windows platforms. Specializes in\n"+
                                  "\t\tDependency Injection, SQLite, JSON, and more.\n", // 7

                                  "\tNOOSPHERE\n", // 8

                                  "\t  Ambassador of Noosphere Engineering School\n", // 9

                                  std::string("")+
                                  "\t\t\t -January 2023 - Present (1 year)\n"
                                  "\t\t\tCollaborates with NOOSPHERE on mini-game development \n"
                                  "\n\nand software products for various platforms.\n" // 10

                                  "\tFreelance\n", // 11
                                  "\t  Self-Employed Developer\n", // 12

                                    std::string("")+
                                  "\t\t -September 2021 - March 2022 (7 months)\n"
                                  "\t\tEngaged in diverse software development, data parsing, bot \n"
                                  "\t\tand site development, with expertise in low-level \n"
                                  "\t\tprogramming and algorithms.\n", //13
                                  "\nKiyv, Ukraine" // 14
                };
    public:
        GamePlayScenesSetting() = default;

        const float screenWidth = 900;
        const float screenHeight = 560;
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
