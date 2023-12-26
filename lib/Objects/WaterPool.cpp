//
// Created by OchiAnthropos on 22.12.2023.
//
#include "Objects.h"

namespace Game::Objects
{
    void WaterPool::UpdateDrawObjects() {
        baseAnimation->DrawAnimation();

        AddToHolder();
    }

    WaterPool::WaterPool(Scene *sceneContext) : GameObject(sceneContext)
    {
        gameObjectName = "WaterPool";
        baseAnimation = new WaterAnimation();
    }


    WaterPool::WaterPool(Scene *sceneContext, int x, int y) : GameObject(sceneContext) {
        gameObjectName = std::string("WaterPool [x:") + std::to_string (x) + std::string(" y:") + std::to_string(y) + std::string("]");
        x_position = x;
        y_position = y;
        baseAnimation = new WaterAnimation();
        baseAnimation->x = x;
        baseAnimation->y = y;
    }

    void WaterPool::AddToHolder() {
        holder.addObject("water_animation",baseAnimation->GetEndFrameSprite());

    }

    void WaterPool::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        gameObjectName = std::string(
                "WaterPool [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
    }
    void WaterPool::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        gameObjectName = std::string(
                "WaterPool [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
    }
}
// Game / Objects