//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
#pragma once
#include "AnimationSettings.h"
#include "FontSettings.h"

namespace Game {
    class GamePlayScenesSetting : public Setting {
        friend class GamePlayScene;

    private:
        const AnimationSettings animationSettings = AnimationSettings();
        const FontSettings fontSettings = FontSettings();
        const std::string ship_type_one_path = GetPath("textures\\ship_type_second.png");
        const std::string ship_type_one_path_die;
        const float ship_type_one_speed = 8.0f;
        const float ship_type_one_speed_expand = 1.1f;
        const float ship_type_one_time_expand = 10.0f;
        const float ship_type_one_time_spawn_min = 3.0f;
        const float ship_type_one_time_spawn_max = 4.0f;
        const float average = 1.0f;
        const float ship_type_one_width = 100.0f;
        const float ship_type_one_height = 30.0f;
        const std::string ship_type_two_path = GetPath("textures\\ship_type_second.png");
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

        const std::string panel = GetPath("textures\\panel.png");
        const std::string button = GetPath("textures\\button.png");
        const std::string infoPanel = GetPath("textures\\infoPanel.png");
        const std::string EndButton = GetPath("textures\\EndButton.png");
        const std::string panelText = GetPath("textures\\panelText.png");
        const std::string flyTex = GetPath("textures\\fly.png");

        std::vector<std::string> information =
                {                 "Voytusik (ochiantropos) Ivan\n", // 0
                                  "Co-Founder & Lead Unity Developer at Wildery\n", // 1
                                  "  Location: Kyiv, Ukraine\n", // 2
                                  "    GitHub Profile https://github.com/ochiantropos\n",// 3
                                  "    Telegram https://t.me/Vanyenot\n",// 4
                                  "    Steam Community https://steamcommunity.com/profiles/7656\n", // 5
                                  "Professional Experience\n", // 6
                                  "\tWildery\n", //7
                                  "\t  Lead Unity Developer\n", //8
                                  "\t\t-April 2022 - Present (1 year, 9 months)\n",// 9
                                  "\t\tRemote work focused on team leadership and software development  \n",//10
                                  "\t\tfor Android and Windows platforms. Specializes in\n",// 11
                                  "\t\tDependency Injection, SQLite, JSON, and more.\n", // 12
                                  "\tNOOSPHERE\n", // 13
                                  "\t  Ambassador of Noosphere Engineering School\n", // 14
                                  "\t\t-January 2023 - Present (1 year)\n",// 15
                                  "\t\tCollaborates with NOOSPHERE on mini-game development \n",// 16
                                  "\t\tand software products for various platforms.\n", // 17
                                  "\tFreelance\n", // 18
                                  "\t  Self-Employed Developer\n", // 19
                                  "\t\t-September 2021 - March 2022 (7 months)\n", // 20
                                  "\t\tEngaged in diverse software development, data parsing, bot \n", //21
                                  "\t\tand site development, with expertise in low-level \n", //22
                                  "\t\tprogramming and algorithms.\n", //23
                                  "\nKiyv, Ukraine" // 24
                };
    public:
        GamePlayScenesSetting() = default;
        const float screenWidth = 1200;
        const float screenHeight = 800;
        const std::string ms = GetPath("good-morning-vietnam.mp3");
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
