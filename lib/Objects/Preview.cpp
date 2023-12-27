//
// Created by OchiAnthropos on 27.12.2023.
//

#include "Objects.h"


namespace Game::Objects {


        void  Preview::UpdateDrawObjects() {
            sprite.setPosition((float) x_position, (float) y_position);
            baseAnimation->DrawAnimation();
            holder.addObject("Preview :" + gameObjectName, baseAnimation->GetEndFrameSprite());
            if (baseAnimation->end) deletable = true;
        }
    Preview::Preview(Scene *sceneContext) : GameObject(sceneContext) {}

    Preview::Preview(Scene *sceneContext, int x, int y)  : GameObject(sceneContext) {
                gameObjectName = std::string(
                        "Preview [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
                baseAnimation = new PreviewAnimation();
                x_position = (float) x;
                y_position = (float) y;
                baseAnimation->x = x;
                baseAnimation->y = y;
        }

    Preview::Preview(Scene *sceneContext, int x, int y, sf::Texture *texture)  : GameObject(sceneContext) {
                gameObjectName = std::string(
                        "Preview [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
                baseAnimation = new PreviewAnimation(texture);
                x_position = (float) x;
                y_position = (float) y;
                baseAnimation->x = x;
                baseAnimation->y = y;
        }

    Preview::Preview(Scene *sceneContext, const sf::Sprite &sprite1, int _x, int _y) : GameObject(sceneContext) {
                sprite = sprite1;
                gameObjectName = std::string(
                "Preview [x:" + std::to_string(_x) + std::string(" y:") + std::to_string(_y) + std::string("]"));

                x_position = (float) _x;
                y_position = (float) _y;
        }

        void Preview::SetPosition(float x, float y) {
            x_position = x;
            y_position = y;
            gameObjectName = std::string(
                    "Preview [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        }

        void Preview::MovePosition(float x, float y) {
            x_position += x;
            y_position += y;
            gameObjectName = std::string(
                    "Preview [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) + std::string("]"));
        }
} // Objects
// Game