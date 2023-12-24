//
// Created by OchiAnthropos on 23.12.2023.
//
#include "GamePlayScene.h"
#include "../Debugger/Debugger.h"
#include "../Objects/Ground.h"

namespace Game {
    GamePlayScene::GamePlayScene(Scene *_scene, int _y_size, int _x_size): SceneHolder(_scene, _y_size, _x_size)  {
        this->scene = _scene;
        CreatePool();
        CreateGround();
        LoadShipTexture();
        CreateShip(0,0);
    }

    void GamePlayScene::CreatePool() const {
        for (int x = 0; x <= (int)((float)x_size/setting.animationSettings.WaterPoolWidth); x++) {
            for (int y = 0; y <= (int)((float)y_size/setting.animationSettings.WaterPoolHeight); y++)
            {
                scene->addObject(new Objects::WaterPool(scene->windowContext, (int)(setting.animationSettings.WaterPoolWidth * (float)x), (int)(setting.animationSettings.WaterPoolHeight * (float)y)), 1);
            }
        }
    }

    void GamePlayScene::CreateGround() const {
        scene->addObject(new Objects::Ground(scene->windowContext, x_size  -55,  (int)(setting.animationSettings.GroundAnimationHeight* (float)0 )), 2);
        scene->addObject(new Objects::Ground(scene->windowContext, x_size  -55,  (int)(setting.animationSettings.GroundAnimationHeight* (float)1 )), 2);
    }

    void GamePlayScene::LoadShipTexture() {
        if (!shipTexture.loadFromFile(setting.ship_type_one_path))
            std::cout << "Error loading texture!" << std::endl;
        shipSprite.setTexture(shipTexture);
        shipSprite.setTextureRect(sf::IntRect(0, 0, (int)setting.ship_type_one_width, (int)setting.ship_type_one_height));
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
        CreatePool();
        CreateGround();
        LoadShipTexture();
        CreateShip(-160,200);

        addCCoroutineFunk("generator",  new Coroutine([this]() { GenerateRandomPosition(); }, 1.0f, 2.0f, 0.5f)  );

        addCCoroutineFunk("ship movement",  new Coroutine([this]() { MoveShips(); }, 0.02f)  );

        addCCoroutineFunk("ship logger",  new Coroutine([this]() { MoveShipLogger(); }, 115.0f)  );

    }

    void GamePlayScene::Update() {
        SceneHolder::Update();
    }

    bool GamePlayScene::checkCollision(const sf::Vector2f &newPos) const {
        return std::any_of(active_ships->begin(), active_ships->end(), [&newPos](Objects::Ship *ship) {
            float ship_left = ship->x_position;
            float ship_right = ship->x_position + ship->width;
            float ship_top = ship->y_position;
            float ship_bottom = ship->y_position + ship->height;

            float new_left = newPos.x;
            float new_right = newPos.x + ship->width;
            float new_top = newPos.y;
            float new_bottom = newPos.y + ship->height;

            return !(new_right < ship_left || new_left > ship_right || new_bottom < ship_top || new_top > ship_bottom);
        });
    }

    void GamePlayScene::GenerateRandomPosition() const {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution_y(20, x_size - 60);
        std::uniform_int_distribution<int> distribution_x(0, 25);

        sf::Vector2f newPosition;
        int x = distribution_x(gen);
        int y = distribution_y(gen);

        newPosition = sf::Vector2f((float)x, (float)y);
        if (!checkCollision(newPosition)){
            CreateShip(newPosition.x, newPosition.y);
            Debugger::Log("New Position: (" + std::to_string(newPosition.x) + ", " + std::to_string(newPosition.y) + ")", Debugger::Color::GREEN);
        } else {
            Debugger::Log("New Position: (" + std::to_string(newPosition.x) + ", " + std::to_string(newPosition.y) + ")", Debugger::Color::RED);
        }
    }

    void GamePlayScene::MoveShips() const {
        for (auto ship : *active_ships) ship->MovePosition(setting.ship_type_one_speed,0);

    }

    void GamePlayScene::MoveShipLogger() const {
        for (auto ship : *active_ships){
            Debugger::Log(
                    std::string ("[ ship ] x=") +
                    std::string (std::to_string (ship->x_position)) +
                    " y=" +
                    std::string (std::to_string (ship->y_position)), Debugger::Color::BLUE );
        }
    }


    GamePlayScene::GamePlayScene() = default;
}
