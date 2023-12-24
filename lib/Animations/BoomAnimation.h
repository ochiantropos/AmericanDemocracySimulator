//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_BOOMANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_BOOMANIMATION_H
#pragma once

#include "Animation.h"

namespace Game {

    class BoomAnimation: public Animation {
    public:
        BoomAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_BOOMANIMATION_H
