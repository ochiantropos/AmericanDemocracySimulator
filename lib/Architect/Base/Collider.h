//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_COLLIDER_H
#define AMERICANDEMOCRACYSIMULATOR_COLLIDER_H

#include "AbstractColliderType.h"

namespace Game {
    template<typename TColliderType>
    class Collider {

    private:
        AbstractColliderType collider{};
    public:
        TColliderType colliderType{};

        explicit Collider(TColliderType coll);

        bool CompareCollider(Collider collider2) {
            return true;
        }
    };


} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_COLLIDER_H
