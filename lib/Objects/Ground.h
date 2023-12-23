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
            void UpdateDrawObjects() override;
            void AddToHolder();

            explicit Ground(sf::RenderWindow *windowContext, int x = 0, int y = 0);
            explicit Ground(sf::RenderWindow* windowContext);
        };

    } // Objects
// Game

#endif //AMERICANDEMOCRACYSIMULATOR_GROUND_H
