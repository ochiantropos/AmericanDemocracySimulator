//
// Created by OchiAnthropos on 22.12.2023.
//
#include "WaterPool.h"
#include "../Animations/WaterAnimation.h"
#include <string>

namespace Game::Objects
{

    WaterPool::WaterPool(sf::RenderWindow *windowContext)
    {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = "WaterPool";
        baseAnimation = new WaterAnimation();
    }

    void WaterPool::UpdateDrawObjects() {
        baseAnimation->DrawAnimation();

        AddToHolder();
    }

    void WaterPool::AddToHolder() {
        holder.addObject("water_animation",baseAnimation->GetEndFrameSprite());

    }

    WaterPool::WaterPool(sf::RenderWindow *windowContext, int x, int y) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
        gameObjectName = std::string("WaterPool [x:") + std::to_string (x) + std::string(" y:") + std::to_string(y) + std::string("]");
        baseAnimation = new WaterAnimation();
        baseAnimation->x = x;
        baseAnimation->y = y;
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