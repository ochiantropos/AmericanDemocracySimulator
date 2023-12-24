//
// Created by OchiAnthropos on 22.12.2023.
//

#include "WaterAnimation.h"

namespace Game {
    WaterAnimation::WaterAnimation() {
        this->frameTime = settings.WaterPoolAnimationFrameTime;
        this->animationName = "water";
        SetFrame(settings.WaterPoolHeight, settings.WaterPoolWidth, settings.WaterPoolAnimationFrame);
        DataParse(settings.WaterPoolPath);
        size = texture.getSize();

    }

    sf::Sprite WaterAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

} // Game