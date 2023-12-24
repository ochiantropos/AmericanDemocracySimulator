//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_COLLIDER_H
#define AMERICANDEMOCRACYSIMULATOR_COLLIDER_H

#include "AbstractCollider.h"

namespace Game {

    template<typename TColliderType>

    class Collider {
    private:
        AbstractCollider collider{};
    public:
        TColliderType colliderType{};

        bool CompareCollider(Collider collider2) {
        }
    };
} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_COLLIDER_H
