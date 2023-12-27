//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
#define AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
#pragma once
#include "Setting.h"

namespace Game {
    class AnimationSettings : public Setting{
        friend class Animation;
        friend class GamePlayScenesSetting;

    public:
        AnimationSettings() = default;

        const float GroundAnimationHeight = 320;
        const float GroundAnimationWidth = 120;
        const float GroundAnimationFrameTime = 0.5f;
        const int GroundAnimationFrame = 14;
         std::string ground_path = GetPath("textures/ground_sheet.png");
        const float WaterPoolWidth = 80.0f;
        const float WaterPoolHeight = 80.0f;
        const float WaterPoolAnimationFrameTime = 0.11f;
        const int WaterPoolAnimationFrame = 21;
         std::string WaterPoolPath = GetPath("textures/sea_game_pool_sheet.png");
        const float PointWidth = 60.0f;
        const float PointHeight = 60.0f;
        const float PointAnimationFrameTime = 0.15f;
        const int PointAnimationFrame = 19;
         std::string PointPath = GetPath("textures/point.png");
        const float DeadWidth = 100.0f;
        const float  DeadHeight = 30.0f;
        const float  DeadAnimationFrameTime = 0.12f;
        const int DeadAnimationFrame = 12;
         std::string  DeadPath = GetPath("textures/ship_type_second_sheet.png");
        const float BoomWidth = 100.0f;
        const float  BoomHeight = 100.0f;
        const float  BoomAnimationFrameTime = 0.1f;
        const int BoomAnimationFrame = 23;
         std::string  BoomPath = GetPath("textures/boom.png");

        const float PHeight = 800;
        const float PWidth = 1200;
        const float PFrameTime = 0.3f;
        const int PFrame = 7;
        std::string PPath = GetPath("textures/prew.png");
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_ANIMATIONSETTINGS_H
