//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H

#include "AbstractGameObject.h"

namespace Game {

    class GameObject{
    public:
        DrawableHolder holder = DrawableHolder();

        sf::Texture texture;
        sf::Sprite sprite;
        float x_position = 0;
        float y_position = 0;
        float height = 18.0f;
        float width = 134.0f;

        void update(float deltaTime) ;

        void draw(sf::RenderWindow &window) ;

        std::map <std::string, sf::Sprite> &getObjects() { return holder.objects; }

        std::string gameObjectName = "GameObject";

        virtual void SetPosition(float x, float y) {}

        virtual void MovePosition(float x, float y) {}

        virtual void UpdateDrawObjects() {};
        Scene *currentContext = nullptr;
        Animation *baseAnimation{};
    };
}// Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
