//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H

#include <string>

namespace Game {
    class AnimationSettings{
        friend class Animation;
        friend class GamePlayScenesSetting;

    public:
        AnimationSettings() = default;

        const float GroundAnimationHeight = 320;
        const float GroundAnimationWidth = 120;
        const float GroundAnimationFrameTime = 0.3f;
        const int GroundAnimationFrame = 14;

        const std::string ground_path = R"(C:\AmericanDemocracySimulator\textures\ground_sheet.png)";

        const float WaterPoolWidth = 80.0f;
        const float WaterPoolHeight = 80.0f;
        const float WaterPoolAnimationFrameTime = 0.11f;
        const int WaterPoolAnimationFrame = 21;

        const std::string WaterPoolPath = R"(C:\AmericanDemocracySimulator\textures\sea_game_pool_sheet.png)";

    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
