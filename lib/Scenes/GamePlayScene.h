//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H


#include "../Objects/Objects.h"

namespace Game {

    class GamePlayScene {

    public:
        GamePlayScene();
        GamePlayScene(Scene *_scene, int _y_size, int _x_size);

        std::vector<Objects::WaterPool> pool;
        int x_size = 0;
        int y_size = 0;
        Scene *scene{};

        sf::Sprite groundSprite;
        sf::Texture groundTexture;

        void CreatePool() const;
        void CreateGround();
    };

} // Game

#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
