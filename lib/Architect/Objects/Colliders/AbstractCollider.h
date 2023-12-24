//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDER_H
#define AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDER_H

#include <SFML/System/Vector2.hpp>
#include "Colliders.h"

namespace Game {

    class AbstractCollider : public ICollider {
    public:
        AbstractCollider();

        sf::Vector2f center = {0, 0};
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDER_H
