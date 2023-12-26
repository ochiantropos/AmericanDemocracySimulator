//
// Created by OchiAnthropos on 24.12.2023.
//
#include "Animation.h"

namespace Game {
    DeadAnimation::DeadAnimation() {
        this->frameTime = settings.DeadAnimationFrameTime;
        this->animationName = "DIE";
        SetFrame(settings.DeadHeight, settings.DeadWidth, settings.DeadAnimationFrame);
        DataParse(settings.DeadPath);
        size = texture.getSize();
    }

    sf::Sprite DeadAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }
} // Game