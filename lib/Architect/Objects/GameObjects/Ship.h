//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SHIP_H
#define AMERICANDEMOCRACYSIMULATOR_SHIP_H

#pragma once

#include "../../Base/GameObject.h"

namespace Game::Objects {

    class Ship : public GameObject{

    public:




        void UpdateDrawObjects() override;

        explicit Ship(sf::RenderWindow *windowContext, const sf::Sprite &sprite, int x, int y);
        explicit Ship(sf::RenderWindow *windowContext, int x, int y);
        explicit Ship(sf::RenderWindow *windowContext);

        void AddToHolder();

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };

} // Objects
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_SHIP_H
