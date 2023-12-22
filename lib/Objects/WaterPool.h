//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
#define AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H

#include "../Architect/GameObject.h"
#include "Animation.h"

namespace Game::Objects {

    class WaterPool : public Game::GameObject {
        sf::Texture texture;
        sf::Sprite sprite;

    public:

        explicit WaterPool(sf::RenderWindow* windowContext);
        void UpdateDrawObjects() override;
        void AddToHolder();

    };
} // Objects

#endif //AMERICANDEMOCRACYSIMULATOR_WATERPOOL_H
