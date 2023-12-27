//
// Created by OchiAnthropos on 21.12.2023.
//



#include "Animation.h"

namespace Game {

    // constructors

    Animation::Animation(sf::Sprite _sprite) {
        sprite = std::move(_sprite);
        animationTimer.restart();

    }
    Animation::Animation(sf::Sprite _sprite, const sf::Texture& _texture) : sprite(std::move(_sprite)), texture(_texture) {
        size = texture.getSize();
        currentFrame = 0;
        animationTimer.restart();
    }
    Animation::Animation(const sf::Texture &_texture) {
        size = texture.getSize();
        currentFrame = 0;
        animationTimer.restart();

    }
    Animation::Animation() {
        DataParse();
        size = texture.getSize();
        animationTimer.restart();
    }

    Animation::Animation(const std::string& path)
    {
        DataParse(path);
        size = texture.getSize();
        animationTimer.restart();
    }
    Animation::Animation(const std::string& path, float speed)
    {
        DataParse(path);
        size = texture.getSize();
        frameTime = speed;
        animationTimer.restart();
    }
    Animation::Animation(float speed){
        DataParse();
        size = texture.getSize();
        frameTime = speed;
        animationTimer.restart();
    };
    Animation::Animation(float speed, std::string animationName) : animationName(std::move(animationName)) {
        DataParse();
        size = texture.getSize();
        frameTime = speed;
        animationTimer.restart();
    }
// ----------------------- data funk -----------------------
    void Animation::DataParse(){
        if (!texture.loadFromFile(R"(C:\AmericanDemocracySimulator\textures\sea_game_pool_water.png)"))
            std::cout << "Error loading texture!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
    }
    void Animation::DataParse(const std::string& path){
        if (!texture.loadFromFile(path)) {
            DataParse();
            std::cout << "Error loading texture!" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
    }
    void Animation::SetFrameWidth(int frame){
        frameWidth = frame;
    }
    void Animation::SetFrameHeight(int frame){
        frameHeight = frame;
    }
    void Animation::SetFrameCount(int frame){
        frameCount = frame;
    }

    void Animation::SetFrame(int h, int w, int c){
        SetFrameWidth(w);
        SetFrameHeight(h);
        SetFrameCount(c);
        ResetAnimation();
    }

    void Animation::DrawAnimation()
    {
        if ( deltaTime > frameTime) {
            deltaTime = 0;
            NextFrame();

        } else {
            float totalTime = animationTimer.restart().asSeconds();
            deltaTime += totalTime;
//            deltaTime = animationTimer.getElapsedTime();
        }
    }

    void Animation::ResetAnimation() {
        currentFrame = (currentFrame) % frameCount;
        sprite.setTextureRect(sf::IntRect(0 * frameWidth, 0 * frameHeight, frameWidth, frameHeight));
        deltaTime = animationTimer.restart().asSeconds();
    }

    void Animation::NextFrame() {
        currentFrame = (currentFrame+1) % frameCount;
        int column = currentFrame % (texture.getSize().x / frameWidth);
        int row = currentFrame / (texture.getSize().x / frameWidth);
//        Debugger::Log("Next animation frame " + std::to_string(column) + " " + std::to_string(row), Debugger::Color::YELLOW);
        sprite.setTextureRect(sf::IntRect(column * frameWidth, row * frameHeight, frameWidth, frameHeight));
        sprite.setPosition((float)x, (float)y);
    }



} // Game