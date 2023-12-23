//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GROUND_H
#define AMERICANDEMOCRACYSIMULATOR_GROUND_H

#include <SFML/Graphics/Sprite.hpp>
#include "../Architect/GameObject.h"

namespace Game::Objects {

        class Ground : public Game::GameObject {

        protected:
            sf::Texture texture;
            sf::Sprite sprite;
        public:
            int x_position = 0;
            int y_position = 0;

            void UpdateDrawObjects() override;

            explicit Ground(sf::RenderWindow *windowContext, const sf::Sprite& sprite1, int _x, int _y);
            explicit Ground(sf::RenderWindow *windowContext, int x = 0, int y = 0);
            explicit Ground(sf::RenderWindow* windowContext);

            void AddToHolder();
        };

    } // Objects
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_GROUND_H
