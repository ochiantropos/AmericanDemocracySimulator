//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
#pragma once
#include "../Architect/Base/Base.h"
#include "../../Settings/AnimationSettings.h"

namespace Game {

    class Animation  {

// frame data
    protected:
        int currentFrame = 0;
        int frameWidth = 16;
        int frameHeight = 16;
        float deltaTime = 0;
        int frameCount = 0;
        sf::Clock animationTimer;
        AnimationSettings settings = AnimationSettings();

    public:
        bool end = false;
        int end_count = 0;

        float x = 0;
        float y = 0;
        float frameTime = 0.2f;
        std::string animationName = "base_animation";
        sf::Vector2<unsigned int> size;
        sf::RenderWindow* window{};
        sf::Texture texture;
        sf::Sprite spritePoint;
        sf::Sprite sprite;

        explicit Animation();
        explicit Animation(float speed);
        explicit Animation(float speed, std::string animationName);
        explicit Animation(sf::Sprite _sprite);
        explicit Animation( const sf::Texture& _texture);
        explicit Animation(sf::Sprite _sprite, const sf::Texture&_texture);
        explicit Animation(const std::string& path);
        explicit Animation(const std::string& path, float speed);

        virtual sf::Sprite GetEndFrameSprite()
        {
            sprite.setPosition(x,y);
            return sprite;
        }


        void NextFrame();
        void ResetAnimation();

        void SetFrameWidth(int frame);

        void SetFrameHeight(int frame);

        void SetFrameCount(int frame);

        void SetFrame(int h, int w, int c);

        void DrawAnimation();

        void DataParse();

        void DataParse(const std::string& path);

    };

    class BoomAnimation: public Animation {
    public:
        BoomAnimation();

        BoomAnimation(sf::Texture *_texture);

        sf::Sprite GetEndFrameSprite() override;
    };

    class DeadAnimation : public Animation {
    public:
        DeadAnimation();

        DeadAnimation(sf::Texture *_texture);

        sf::Sprite GetEndFrameSprite() override;
    };

    class GroundAnimation : public Animation {

    public:
        GroundAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };

    class PointAnimation : public Animation {
    public:
        PointAnimation();

        sf::Sprite GetEndFrameSprite() override;
    };

    class WaterAnimation : public Animation {

    public:
        WaterAnimation();
        sf::Sprite GetEndFrameSprite() override;
    };

    class PreviewAnimation : public Animation{
        sf::Sprite GetEndFrameSprite() override;

    public:
        PreviewAnimation();

        PreviewAnimation(sf::Texture *_texture);
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
