//
// Created by OchiAnthropos on 22.12.2023.
//

#include "WaterAnimation.h"

namespace Game {
    WaterAnimation::WaterAnimation() {
        this->frameTime = 0.11f;
        this->animationName = "water";
        SetFrame(80, 80, 21);
        DataParse(R"(C:\AmericanDemocracySimulator\textures\sea_game_pool_sheet.png)");
        size = texture.getSize();

    }

    sf::Sprite WaterAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

} // Game