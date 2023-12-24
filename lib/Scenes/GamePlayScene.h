//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#pragma once

#include <SFML/Graphics.hpp>

#include "../Architect/Base/SceneHolder.h"
#include "../../Settings/GamePlaySceneSettings.h"
#include "../Objects/Ship.h"
#include "../Objects/WaterPool.h"
#include "../Objects/Point.h"

namespace Game {

    class GamePlayScene : public SceneHolder {
        GamePlayScenesSetting setting = GamePlayScenesSetting();

    protected:

        std::vector<Objects::WaterPool> pool;
        std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();

        sf::Sprite shipSprite;
        sf::Texture shipTexture;

        sf::Sprite shipType2Sprite;
        sf::Texture shipType2Texture;

        Objects::Point *pointObject;

        void CreatePool() const;
        void CreateGround() const;
        void LoadShipTexture();
        void CreateShip(float x, float y) const;
        // patch -1-0-3.4
        void MoveShipLogger() const;
        void MoveShips() const;
        void GenerateRandomPosition() const;
        bool checkCollision(const sf::Vector2f& newPos) const;
        // patch -1-2-1
        void CreatePoint();

    public:
            GamePlayScene();
            GamePlayScene(Scene *_scene, int _y_size, int _x_size);


            void OnClicked() override;
            void OnClickedStart() override;
            void OnClickedEnd() override;

            // overriding
            void Update() override;
            void Start() override;

    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
