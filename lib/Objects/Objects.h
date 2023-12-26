//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_OBJECTS_H
#define AMERICANDEMOCRACYSIMULATOR_OBJECTS_H
#pragma once
#include "../Architect/Architect.h"

namespace Game::Objects {


    class Ground : public Game::GameObject {

    public:
        void UpdateDrawObjects() override;

        explicit Ground(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Ground(Scene *sceneContext, int x = 0, int y = 0);
        explicit Ground(Scene *sceneContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
        void AddToHolder();
    };
    class DeadShip : GameObject {
        void UpdateDrawObjects() override;

        explicit DeadShip(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit DeadShip(Scene *sceneContext, int x = 0, int y = 0);
        explicit DeadShip(Scene *sceneContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };
    class Point : public GameObject {
        void UpdateDrawObjects() override;

        explicit Point(Scene *sceneContext,
                       const sf::Sprite &sprite1,
                       int _x,
                       int _y
        );

        explicit Point(Scene *sceneContext);

    public:
        void SetPosition(float x, float y) override;
        void MovePosition(float x, float y) override;
        explicit Point(Scene *sceneContext,
                       int x = 0,
                       int y = 0
        );
    };

    class WaterPool : public Game::GameObject {

    public:
        explicit WaterPool(Scene *sceneContext, int x = 0, int y = 0);
        explicit WaterPool(Scene* sceneContext);

        void UpdateDrawObjects() override;
        void AddToHolder();
        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;

    };

    class ShipDieAnimated {

    };

    class Ship : public GameObject{
    public:

        void UpdateDrawObjects() override;

        explicit Ship(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Ship(Scene *sceneContext, int x = 0, int y = 0);
        explicit Ship(Scene *sceneContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };

    class Boom : public GameObject {
        void UpdateDrawObjects() override;

        explicit Boom(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Boom(Scene *sceneContext, int x = 0, int y = 0);
        explicit Boom(Scene *sceneContext);

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_OBJECTS_H
