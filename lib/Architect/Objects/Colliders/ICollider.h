//
// Created by OchiAnthropos on 24.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ICOLLIDER_H
#define AMERICANDEMOCRACYSIMULATOR_ICOLLIDER_H

#include "Colliders.h"
namespace Game {

    class ICollider {
    public:
        bool CheckCollision(CircleCollider collider1, CircleCollider collider2);

        bool CheckCollision(CircleCollider collider1, RectangleCollider collider2);

        bool CheckCollision(RectangleCollider collider1, CircleCollider collider2);

        bool CheckCollision(RectangleCollider collider1, RectangleCollider collider2);
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_ICOLLIDER_H
