//
// Created by OchiAnthropos on 23.12.2023.
//
#include "GamePlayScene.h"
#include "../Debugger/Debugger.h"

namespace Game {
    GamePlayScene::GamePlayScene(Scene *_scene, int _y_size, int _x_size): scene(_scene), y_size(_y_size), x_size(_x_size)  {
        CreatePool();
    }

    void GamePlayScene::CreatePool() const {
        for (int x = 0; x <= x_size; x++) {
            for (int y = 0; y <= y_size; y++)
            {
                Debugger::Log( std::to_string(x) + " " + std::to_string(y ) , Debugger::Color::YELLOW);
                scene->addObject(new Objects::WaterPool(scene->windowContext, 80 * x, 80 * y), 1);
            }
        }
    }

    void GamePlayScene::CreateGround() {
        if (!groundTexture.loadFromFile(R"(C:\AmericanDemocracySimulator\textures\ground.png)"))
            std::cout << "Error loading texture!" << std::endl;
        groundSprite.setTexture(groundTexture);

    }


    GamePlayScene::GamePlayScene() = default;
} // G
