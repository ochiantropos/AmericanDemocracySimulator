//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H


#include "../Objects/Objects.h"
#include "../Objects/Ship.h"

namespace Game {

    class GamePlayScene {

    public:
        GamePlayScene();
        GamePlayScene(Scene *_scene, int _y_size, int _x_size);

        std::vector<Objects::WaterPool> pool;
        int x_size = 0;
        int y_size = 0;
        Scene *scene{};

        std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();

        sf::Sprite shipSprite;
        sf::Texture shipTexture;

        void CreatePool() const;
        void CreateGround() const;

        void LoadShipTexture();

        void CreateShip(float x, float y) const;
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
