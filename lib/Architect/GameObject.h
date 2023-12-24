//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AbstractGameObject.h"
#include "Scene.h"
#include "../Animations/Animation.h"

namespace Game {

    class Scene;

    class GameObject : public AbstractGameObject{

    public:

        GameObject();
        explicit GameObject(Scene *context);
        void update(float deltaTime) override;
        void draw(sf::RenderWindow& window) override;
        std::map<std::string, sf::Sprite>& getObjects() {return holder.objects;}
        std::string gameObjectName = "GameObject";

        virtual void  UpdateDrawObjects() = 0;

    public:
        Scene *currentContext = nullptr;
        Animation *baseAnimation;
    };

    } // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEOBJECT_H
