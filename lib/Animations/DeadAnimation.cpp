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

    DeadAnimation::DeadAnimation(sf::Texture *_texture) {
        this->frameTime = settings.DeadAnimationFrameTime;
        this->animationName = "DIE";
        SetFrame(settings.DeadHeight, settings.DeadWidth, settings.DeadAnimationFrame);
        texture = *_texture;
        size = texture.getSize();
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
    }
    sf::Sprite DeadAnimation::GetEndFrameSprite() {
        if (currentFrame==frameCount-1)
        {
            end = true;
        }
        return Animation::GetEndFrameSprite();
    }
} // Game