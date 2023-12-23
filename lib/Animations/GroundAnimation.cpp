//
// Created by OchiAnthropos on 23.12.2023.
//

#include "GroundAnimation.h"

namespace Game {
    sf::Sprite GroundAnimation::GetEndFrameSprite() {
        return Animation::GetEndFrameSprite();
    }

    GroundAnimation::GroundAnimation() {
        this->frameTime = 0.3f;
        this->animationName = "ground";
        SetFrame(320, 120, 14);
        DataParse(R"(C:\AmericanDemocracySimulator\textures\ground_sheet.png)");
        size = texture.getSize();
    }
} // Game