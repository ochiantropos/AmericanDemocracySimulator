//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H

#include <string>
#include "AnimationSettings.h"

namespace Game {
    class GamePlayScenesSetting {
        friend class GamePlayScene;

    private:

        const AnimationSettings animationSettings = AnimationSettings();

        const std::string ship_type_one_path = R"(C:\AmericanDemocracySimulator\textures\ship.png)";
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


    public:
        GamePlayScenesSetting() = default;
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENESETTINGS_H
