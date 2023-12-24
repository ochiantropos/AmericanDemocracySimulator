//
// Created by OchiAnthropos on 21.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_ABSTRACTGAMEOBJECT_H
#define AMERICANDEMOCRACYSIMULATOR_ABSTRACTGAMEOBJECT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "HolderableObject.h"

namespace Game{

    class  AbstractGameObject : public  HolderableObject{
    public:
        virtual void update(float deltaTime) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_ABSTRACTGAMEOBJECT_H
