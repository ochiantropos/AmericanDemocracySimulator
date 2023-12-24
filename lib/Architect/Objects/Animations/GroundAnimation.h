//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GROUNDANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_GROUNDANIMATION_H

#pragma once
#include "Animations.h"

namespace Game {


    class GroundAnimation : public Animation {

    public:
        GroundAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GROUNDANIMATION_H
