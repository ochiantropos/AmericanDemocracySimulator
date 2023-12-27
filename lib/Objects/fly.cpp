//
// Created by OchiAnthropos on 27.12.2023.
//

#include "Objects.h"
namespace Game::Objects {
    void Fly::UpdateDrawObjects() {
        sprite.setPosition(x_position, y_position);
        holder.addObject(gameObjectName, sprite);
    }
    Fly::Fly(Scene *sceneContext) : GameObject(sceneContext) {
    }

    Fly::Fly(Scene *sceneContext, int x, int y)  : GameObject(sceneContext){
        gameObjectName = std::string(
                "Fly [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
        baseAnimation = new PointAnimation();
        baseAnimation->x = x;
        baseAnimation->y = y;
    }
    Fly::Fly(Scene *sceneContext, const sf::Sprite &sprite1, int _x, int _y) : GameObject(sceneContext) {
        sprite = sprite1;
        baseAnimation = new PointAnimation();
        baseAnimation->x = _x;
        baseAnimation->y = _y;
    }

    void Fly::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        sprite.setPosition(x_position-35, y_position-35);
    }

    void Fly::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        sprite.setPosition(x_position-35, y_position-35);
    }

    Fly::Fly(Scene *sceneContext, const sf::Texture &tex, int _x, int _y) : GameObject(sceneContext)  {
        texture = tex;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect( 0, 0, 120,71));
        baseAnimation = new PointAnimation();
        x_position = _x;
        y_position = _y;
        sprite.setPosition(x_position-35, y_position-35);

    }
    void Fly::DoRapair(float _x_max) {
        available = true;
        SetPosition(_x_max+200,0);
        state = State::STAY;
    }
} // Objects
// Game
