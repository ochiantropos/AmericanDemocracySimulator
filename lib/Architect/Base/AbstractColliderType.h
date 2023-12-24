//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDERTYPE_H
#define AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDERTYPE_H

#include <SFML/System/Vector2.hpp>

namespace Game {

    class AbstractColliderType {
    public:
        AbstractColliderType();

        sf::Vector2f center = {0, 0};
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_ABSTRACTCOLLIDERTYPE_H
