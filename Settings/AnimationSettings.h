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
        const float GroundAnimationFrameTime = 0.5f;
        const int GroundAnimationFrame = 14;

        const std::string ground_path = R"(C:\AmericanDemocracySimulator\textures\ground_sheet.png)";

        const float WaterPoolWidth = 80.0f;
        const float WaterPoolHeight = 80.0f;
        const float WaterPoolAnimationFrameTime = 0.11f;
        const int WaterPoolAnimationFrame = 21;

        const std::string WaterPoolPath = R"(C:\AmericanDemocracySimulator\textures\sea_game_pool_sheet.png)";

        const float PointWidth = 20.0f;
        const float PointHeight = 20.0f;
        const float PointAnimationFrameTime = 0.15f;
        const int PointAnimationFrame = 19;
        const std::string PointPath = R"(C:\AmericanDemocracySimulator\textures\point.png)";

        const float DeadWidth = 100.0f;
        const float  DeadHeight = 30.0f;
        const float  DeadAnimationFrameTime = 0.12f;
        const int DeadAnimationFrame = 12;
        const std::string  DeadPath = R"(C:\AmericanDemocracySimulator\textures\ship_type_second_sheet.png)";

        const float BoomWidth = 100.0f;
        const float  BoomHeight = 100.0f;
        const float  BoomAnimationFrameTime = 0.1f;
        const int BoomAnimationFrame = 23;
        const std::string  BoomPath = R"(C:\AmericanDemocracySimulator\textures\boom.png)";


    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
