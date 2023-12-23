//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_SHIP_H
#define AMERICANDEMOCRACYSIMULATOR_SHIP_H


#include "../Architect/GameObject.h"

namespace Game::Objects {

    class Ship : public GameObject{

    protected:
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        float x_position = 0;
        float y_position = 0;

        void UpdateDrawObjects() override;

        explicit Ship(sf::RenderWindow *windowContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Ship(sf::RenderWindow *windowContext, int x = 0, int y = 0);
        explicit Ship(sf::RenderWindow* windowContext);

        void AddToHolder();

        void SetPosition(float x, float y);
    };

} // Objects
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_SHIP_H
