//
// Created by OchiAnthropos on 22.12.2023.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <utility>
#include <SFML/Graphics/Sprite.hpp>
#include "DrawableHolder.h"


namespace Game {

    DrawableHolder::DrawableHolder() = default;

    void DrawableHolder::removeObject(const std::string &key) {
    }

    void DrawableHolder::addObject(const std::string &key, sf::Sprite object) {
        objects[key] = std::move(object);

    }

    void DrawableHolder::DeleteDrawable(const sf::Sprite& object, const std::string &name) {

    }

    void DrawableHolder::DeleteDrawable(std::string &name) {

    }

    void DrawableHolder::AddDrawable(sf::Sprite object) {
        addObject("none",std::move(object));
    }

    void DrawableHolder::AddDrawable(sf::Sprite object, const std::string &name) {
        addObject(name,std::move(object));
    }

    DrawableHolder::DrawableHolder(const std::map<std::string,sf::Sprite>& vectorData) {

    }


}