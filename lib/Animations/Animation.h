//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
#define AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Architect/HolderableObject.h"

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

    public:


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

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_ANIMATION_H
