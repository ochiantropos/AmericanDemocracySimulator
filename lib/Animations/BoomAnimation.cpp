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

    BoomAnimation::BoomAnimation(sf::Texture *_texture) {
        this->frameTime = settings.DeadAnimationFrameTime;
        this->animationName = "DIE";
        SetFrame(settings.BoomHeight, settings.BoomWidth, settings.BoomAnimationFrame);
        texture = *_texture;
        size = texture.getSize();
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
    }

    sf::Sprite BoomAnimation::GetEndFrameSprite() {
        if (currentFrame==frameCount-1)
        {
            end = true;
        }
        return Animation::GetEndFrameSprite();
    }
} // Game