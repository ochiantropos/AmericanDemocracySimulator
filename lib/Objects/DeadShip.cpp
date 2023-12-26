//
// Created by OchiAnthropos on 24.12.2023.
//

#include "Objects.h"

namespace Game::Objects {
    void  DeadShip::UpdateDrawObjects() {
        sprite.setPosition((float) x_position, (float) y_position);
        holder.addObject("DeadShip", sprite);
    }

    DeadShip::DeadShip(Scene *sceneContext) : GameObject(sceneContext) {
    }

    DeadShip::DeadShip(Scene *sceneContext, int x, int y)  : GameObject(sceneContext) {

        gameObjectName = std::string(
                "DeadShip [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));

        x_position = (float) x;
        y_position = (float) y;
    }

    DeadShip::DeadShip(Scene *sceneContext, const sf::Sprite &sprite1, int _x, int _y) : GameObject(sceneContext) {
        sprite = sprite1;
        gameObjectName = std::string(
                "DeadShip [x:" + std::to_string(_x) + std::string(" y:") + std::to_string(_y) + std::string("]"));

        x_position = (float) _x;
        y_position = (float) _y;
    }

    void DeadShip::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        gameObjectName = std::string(
                "DeadShip [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
    }

    void DeadShip::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        gameObjectName = std::string(
                "DeadShip [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
    }
} // Objects
// Game