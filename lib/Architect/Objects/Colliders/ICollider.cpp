//
// Created by OchiAnthropos on 24.12.2023.
//

#include "ICollider.h"

namespace Game {
    bool ICollider::CheckCollision(RectangleCollider collider1, CircleCollider collider2) {
        return false;
    }

    bool ICollider::CheckCollision(CircleCollider collider1, RectangleCollider collider2) {
        return false;
    }

    bool ICollider::CheckCollision(CircleCollider collider1, CircleCollider collider2) {
        return false;
    }

    bool ICollider::CheckCollision(RectangleCollider collider1, RectangleCollider collider2) {
        return false;
    }
} // Game