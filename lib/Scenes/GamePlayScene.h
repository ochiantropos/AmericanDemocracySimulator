//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H


#include "../Objects/Objects.h"
#include "../Objects/Ship.h"
#include "../Architect/Base/SceneHolder.h"
#include "../../Settings/GamePlaySceneSettings.h"

namespace Game {

    class GamePlayScene : public SceneHolder {
        GamePlayScenesSetting setting = GamePlayScenesSetting();
        public:
            GamePlayScene();
            GamePlayScene(Scene *_scene, int _y_size, int _x_size);

            std::vector<Objects::WaterPool> pool;
            std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();

            sf::Sprite shipSprite;
            sf::Texture shipTexture;

            sf::Sprite shipType2Sprite;
            sf::Texture shipType2Texture;

            void CreatePool() const;
            void CreateGround() const;
            void LoadShipTexture();
            void CreateShip(float x, float y) const;
            // patch -1-0-3.4
            void MoveShipLogger() const;
            void MoveShips() const;
            void GenerateRandomPosition() const;
            bool checkCollision(const sf::Vector2f& newPos) const;

            void OnClicked() override;
            void OnClickedStart() override;
            void OnClickedEnd() override;

            // overriding
            void Update() override;
            void Start() override;
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
