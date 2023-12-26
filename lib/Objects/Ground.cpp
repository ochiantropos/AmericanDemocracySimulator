//
// Created by OchiAnthropos on 23.12.2023.
//

#include "Objects.h"


namespace Game::Objects {
    Ground::Ground(Scene *sceneContext, int x, int y) : GameObject(sceneContext) {
        gameObjectName = std::string ("GroundAnimation [x:" + std::to_string(x) + std::string(" y:") +  std::to_string(y) + std::string ("]"));
        baseAnimation = new GroundAnimation();
        baseAnimation->y = y;
        baseAnimation->x = x;
        x_position = x;
        y_position = y;
    }

    Ground::Ground(Scene *sceneContext) : GameObject(sceneContext) {
        gameObjectName = "GroundAnimation";
        baseAnimation = new GroundAnimation();
    }

    Ground::Ground(Scene *sceneContext, const sf::Sprite &sprite1, int _x, int _y) : GameObject(sceneContext) {
        gameObjectName = "GroundAnimation" + std::to_string(_x) + "_" +  std::to_string(_y);
        baseAnimation = new GroundAnimation();
        x_position = _x;
        y_position = _y;
    }

    void Ground::AddToHolder() {holder.addObject("ground_animation", baseAnimation->GetEndFrameSprite());}

    void Ground::UpdateDrawObjects() { baseAnimation->DrawAnimation(); AddToHolder(); }


    void Ground::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        gameObjectName = std::string(
                "Ground [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
    }
    void Ground::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        gameObjectName = std::string(
                "Ground [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
    }
} // Objects
// Game