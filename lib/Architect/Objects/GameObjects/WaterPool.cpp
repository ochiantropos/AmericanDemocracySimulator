//
// Created by OchiAnthropos on 22.12.2023.
//
#include "WaterPool.h"
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
}
// Game / Objects