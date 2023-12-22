//
// Created by OchiAnthropos on 22.12.2023.
//

#include "WaterPool.h"
#include "WaterAnimation.h"

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
        holder.addObject("animation",baseAnimation->GetEndFrameSprite());

    }
}
// Game / Objects