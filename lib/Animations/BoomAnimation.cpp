//
// Created by OchiAnthropos on 24.12.2023.
//
#include "Animation.h"



namespace Game {
    BoomAnimation::BoomAnimation() {
        this->frameTime = settings.BoomAnimationFrameTime;
        this->animationName = "Boom";
        SetFrame(settings.BoomHeight, settings.BoomWidth, settings.BoomAnimationFrame);
        DataParse(settings.BoomPath);
        size = texture.getSize();
    }

    sf::Sprite BoomAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }
} // Game