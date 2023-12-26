//
// Created by OchiAnthropos on 23.12.2023.
//
#include "Animation.h"


namespace Game {
    sf::Sprite GroundAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

    GroundAnimation::GroundAnimation() {
        this->frameTime = settings.GroundAnimationFrameTime;
        this->animationName = "ground";
        SetFrame(settings.GroundAnimationHeight, settings.GroundAnimationWidth, settings.GroundAnimationFrame);
        DataParse(settings.ground_path);
        size = texture.getSize();
    }
} // Game