//
// Created by OchiAnthropos on 24.12.2023.
//
#include "Objects.h"


namespace Game::Objects {
    void Point::UpdateDrawObjects() {
        baseAnimation->DrawAnimation();
        holder.addObject("Point", baseAnimation->GetEndFrameSprite());
    }
    Point::Point(Scene *sceneContext) : GameObject(sceneContext) {
    }

    Point::Point(Scene *sceneContext, int x, int y)  : GameObject(sceneContext){
        gameObjectName = std::string(
                "Point [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        baseAnimation = new PointAnimation();
        baseAnimation->x = x;
        baseAnimation->y = y;
    }

    Point::Point(Scene *sceneContext, const sf::Sprite &sprite1, int _x, int _y) : GameObject(sceneContext) {
        sprite = sprite1;
        gameObjectName = std::string(
                "Point [x:" + std::to_string(_x) + std::string(" y:") + std::to_string(_y) + std::string("]"));
        baseAnimation = new PointAnimation();
        baseAnimation->x = _x;
        baseAnimation->y = _y;
    }

    void Point::SetPosition(float x, float y) {
        gameObjectName = std::string(
                "Point [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        baseAnimation->x = x;
        baseAnimation->y = y;
    }

    void Point::MovePosition(float x, float y) {
        gameObjectName = std::string(
                "Point [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) +
                std::string("]"));
        baseAnimation->x = x;
        baseAnimation->y = y;
    }
}// Object
// Game