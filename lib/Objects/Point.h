//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_POINT_H
#define AMERICANDEMOCRACYSIMULATOR_POINT_H

#pragma once

#include "../Architect/GameObject.h"

namespace Game::Objects {

    class Point : public GameObject {
        void UpdateDrawObjects() override;

        explicit Point(sf::RenderWindow
        *windowContext,
        const sf::Sprite &sprite1,
        int _x,
        int _y
        );

        explicit Point(sf::RenderWindow
        * windowContext);

    public:
        void SetPosition(float x, float y) override;
        void MovePosition(float x, float y) override;
        explicit Point(sf::RenderWindow
        *windowContext,
        int x = 0,
        int y = 0
        );
    };

}// Object
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_POINT_H
