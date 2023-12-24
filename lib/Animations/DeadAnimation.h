//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_DEADANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_DEADANIMATION_H
#pragma once

#include "Animation.h"

namespace Game {

    class DeadAnimation : public Animation {
    public:
        DeadAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_DEADANIMATION_H
