//
// Created by OchiAnthropos on 24.12.2023.
//
#include "Point.h"


namespace Game::Objects {
    void Point::UpdateDrawObjects() {
        sprite.setPosition((float) x_position, (float) y_position);
        holder.addObject("ShipObject", sprite);
    }

    Point::Point(sf::RenderWindow *windowContext) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;
    }

    Point::Point(sf::RenderWindow *windowContext, int x, int y) {
        if (currentContext != nullptr) currentContext->windowContext = windowContext;

        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));

        x_position = (float) x;
        y_position = (float) y;
    }

    Point::Point(sf::RenderWindow *windowContext, const sf::Sprite &sprite1, int _x, int _y) {
        sprite = sprite1;
        if (currentContext != nullptr) currentContext->windowContext = windowContext;

        gameObjectName = std::string(
                "Ship [x:" + std::to_string(_x) + std::string(" y:") + std::to_string(_y) + std::string("]"));

        x_position = (float) _x;
        y_position = (float) _y;
    }

    void Point::SetPosition(float x, float y) {
        x_position = x;
        y_position = y;
        gameObjectName = std::string(
                "Ship [x:" + std::to_string(x) + std::string(" y:") + std::to_string(y) + std::string("]"));
    }

    void Point::MovePosition(float x, float y) {
        x_position += x;
        y_position += y;
        gameObjectName = std::string(
                "Point [x:" + std::to_string(x_position) + std::string(" y:") + std::to_string(y_position) +
                std::string("]"));
    }
}// Object
// Game