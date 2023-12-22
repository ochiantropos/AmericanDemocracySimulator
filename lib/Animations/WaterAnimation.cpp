//
// Created by OchiAnthropos on 22.12.2023.
//

#include "WaterAnimation.h"

namespace Game {
    WaterAnimation::WaterAnimation() {
        this->frameTime = 0.3;
        this->animationName = "water";
        SetFrame(16, 16, 21);
        DataParse();
        size = texture.getSize();
    }

    sf::Sprite WaterAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

} // Game