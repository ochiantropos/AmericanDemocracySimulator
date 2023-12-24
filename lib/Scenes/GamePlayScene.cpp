//
// Created by OchiAnthropos on 23.12.2023.
//
#include "GamePlayScene.h"
#include "../Debugger/Debugger.h"
#include "../Objects/Ground.h"
#include "../Objects/Ship.h"

namespace Game {
    GamePlayScene::GamePlayScene(Scene *_scene, int _y_size, int _x_size): SceneHolder(_scene, _y_size, _x_size)  {
        this->scene = _scene;
        CreatePool();
        CreateGround();
        LoadShipTexture();
        CreateShip(0,0);
    }

    void GamePlayScene::CreatePool() const {
        for (int x = 0; x <= x_size/80; x++) {
            for (int y = 0; y <= y_size/80; y++)
            {
                scene->addObject(new Objects::WaterPool(scene->windowContext, 80 * x, 80 * y), 1);
            }
        }
    }

    void GamePlayScene::CreateGround() const {
        scene->addObject(new Objects::Ground(scene->windowContext, x_size  -55,  320*0 ), 2);
        scene->addObject(new Objects::Ground(scene->windowContext, x_size  -55,  320*1 ), 2);
    }

    void GamePlayScene::LoadShipTexture() {
        if (!shipTexture.loadFromFile(R"(C:\AmericanDemocracySimulator\textures\ship.png)"))
            std::cout << "Error loading texture!" << std::endl;
        shipSprite.setTexture(shipTexture);
        shipSprite.setTextureRect(sf::IntRect(0, 0, 269, 36));
    }

    void GamePlayScene::CreateShip(float x = 0 , float y = 0) const
    {
        auto* ship = new Objects::Ship(scene->windowContext,shipSprite,0 ,0);
        ship->SetPosition(x,y);

        active_ships->push_back(ship);

        scene->addObject(ship,3);

    }

    void GamePlayScene::Start() {
        SceneHolder::Start();
    }

    void GamePlayScene::Update() {
        SceneHolder::Update();
    }

    bool GamePlayScene::checkCollision(const sf::Vector2f &newPos) const {
        return false;
    }

    void GamePlayScene::GenerateRandomPosition() const {

    }

    void GamePlayScene::MoveShips() const {

    }

    void GamePlayScene::MoveShipLogger() const {

    }


    GamePlayScene::GamePlayScene() = default;
}
