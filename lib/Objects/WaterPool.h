//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
#define AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H

#include "../Architect/GameObject.h"

namespace Game::Objects {

    class WaterPool : public Game::GameObject {

    public:
        explicit WaterPool(sf::RenderWindow *windowContext, int x = 0, int y = 0);
        explicit WaterPool(sf::RenderWindow* windowContext);

        void UpdateDrawObjects() override;
        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;

        void AddToHolder();

    };
} // Objects

#endif //AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
