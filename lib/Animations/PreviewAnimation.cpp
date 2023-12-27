//
// Created by OchiAnthropos on 27.12.2023.
//


#include "Animation.h"

namespace Game {

    PreviewAnimation::PreviewAnimation() {
        this->frameTime = settings.PFrameTime;
        this->animationName = "Preview";
        SetFrame(settings.PHeight, settings.PWidth, settings.PFrame);
        DataParse(settings.PPath);
        size = texture.getSize();
    }

    PreviewAnimation::PreviewAnimation(sf::Texture *_texture) {
        this->frameTime = settings.PFrameTime;
        this->animationName = "Preview";
        SetFrame(settings.PHeight, settings.PWidth, settings.PFrame);
        texture = *_texture;
        size = texture.getSize();
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
    }

    sf::Sprite PreviewAnimation::GetEndFrameSprite() {
        if (currentFrame==frameCount-1)
        {
            end = true;
        }
        return Animation::GetEndFrameSprite();
    }
} // Game