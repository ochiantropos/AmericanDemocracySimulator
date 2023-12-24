//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_WATERANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_WATERANIMATION_H
#pragma once

#include "Animation.h"

namespace Game {

    class WaterAnimation : public Animation {

    public:
        WaterAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_WATERANIMATION_H
