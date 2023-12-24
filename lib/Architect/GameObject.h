//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "AbstractGameObject.h"
#include "Scene.h"
#include "../Animations/Animation.h"

namespace Game {

    class Scene;

    class GameObject : public AbstractGameObject{

    public:

        float width = 0;
        float height = 0;
        float x_position = 0;
        float y_position = 0;

        GameObject();
        explicit GameObject(Scene *context);
        void update(float deltaTime) override;
        void draw(sf::RenderWindow& window) override;
        std::map<std::string, sf::Sprite>& getObjects() {return holder.objects;}
        std::string gameObjectName = "GameObject";
        virtual void  UpdateDrawObjects() = 0;
        virtual void SetPosition(float x, float y ) {};
        virtual void MovePosition(float x, float y)  {};

        Scene *currentContext = nullptr;
        Animation *baseAnimation {};
    };

    } // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
