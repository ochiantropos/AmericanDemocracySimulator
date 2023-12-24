//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H

#pragma once

#include "../Objects/Objects.h"
#include "../Objects/GameObjects/Ship.h"
#include "../Holders/SceneHolder.h"
#include "../../../Settings/GamePlaySceneSettings.h"

namespace Game {

    class GamePlayScene : public Game::SceneHolder{
        // base overrides
        GamePlayScenesSetting setting = GamePlayScenesSetting();
    public:
        GamePlayScene(Scene *_scene, int _y_size, int _x_size);
        void Update() override;
        void Start() override;

        std::vector<Objects::WaterPool> pool;
        int x_size = 0;
        int y_size = 0;

        std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();

        sf::Sprite shipSprite;
        sf::Texture shipTexture;
        sf::Sprite shipType2Sprite;
        sf::Texture shipType2Texture;

        void CreatePool() const;
        void CreateGround() const;
        void GenerateRandomPosition() const;

        void LoadShipTexture();
        void CreateShip(float x, float y) const;

        bool checkCollision(const sf::Vector2f &newPos) const;

        void MoveShips() const;

        void MoveShipLogger() const;
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
