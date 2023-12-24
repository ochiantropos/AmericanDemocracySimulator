//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_POINTANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_POINTANIMATION_H
#pragma once

#include "Animation.h"

namespace Game {

    class PointAnimation : public Animation {
    public:
        PointAnimation();

        sf::Sprite GetEndFrameSprite() override;
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_POINTANIMATION_H
