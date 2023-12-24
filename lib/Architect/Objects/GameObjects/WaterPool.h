//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
#define AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
#pragma once

#include "../../Base/GameObject.h"

namespace Game::Objects {

    class WaterPool : public GameObject {

    protected:
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        explicit WaterPool(sf::RenderWindow *windowContext, int x = 0, int y = 0);
        explicit WaterPool(sf::RenderWindow* windowContext);

        void UpdateDrawObjects() override;
        void AddToHolder();

    };
} // Objects

#endif //AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
