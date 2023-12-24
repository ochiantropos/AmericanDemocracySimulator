//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_DEADSHIP_H
#define AMERICANDEMOCRACYSIMULATOR_DEADSHIP_H
#pragma once


#include "../Architect/GameObject.h"

namespace Game::Objects {

    class DeadShip : GameObject {
        void UpdateDrawObjects() override;

        explicit DeadShip(sf::RenderWindow *windowContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit DeadShip(sf::RenderWindow *windowContext, int x = 0, int y = 0);
        explicit DeadShip(sf::RenderWindow* windowContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };

}// Objects
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_DEADSHIP_H
