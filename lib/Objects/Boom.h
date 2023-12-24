//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_BOOM_H
#define AMERICANDEMOCRACYSIMULATOR_BOOM_H
#pragma once
#include "../Architect/GameObject.h"

namespace Game::Objects {
    class Boom : public GameObject {
        void UpdateDrawObjects() override;

        explicit Boom(sf::RenderWindow *windowContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Boom(sf::RenderWindow *windowContext, int x = 0, int y = 0);
        explicit Boom(sf::RenderWindow* windowContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };

}
#endif //AMERICANDEMOCRACYSIMULATOR_BOOM_H
