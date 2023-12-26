//
// Created by OchiAnthropos on 24.12.2023.
//
#include "Animation.h"


namespace Game {

    PointAnimation::PointAnimation() {
        this->frameTime = settings.PointAnimationFrameTime;
        this->animationName = "Point";
        SetFrame(settings.PointHeight, settings.PointWidth, settings.PointAnimationFrame);
        DataParse(settings.PointPath);
        size = texture.getSize();
    }

    sf::Sprite PointAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

} // Game