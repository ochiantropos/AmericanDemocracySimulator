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
    class DeadShip : public GameObject {

        void UpdateDrawObjects() override;

    public:
        explicit DeadShip(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit DeadShip(Scene *sceneContext);
        ~DeadShip() override{};
        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
        explicit DeadShip(Scene *sceneContext, int x = 0, int y = 0);

        DeadShip(Scene *sceneContext, int x, int y, sf::Texture *texture);
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
        ~Ship() = default;
        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
    };

    class Boom : public GameObject {

        void UpdateDrawObjects() override;

        explicit Boom(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);

        explicit Boom(Scene *sceneContext);;

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;

    public:
        explicit Boom(Scene *sceneContext, int x = 0, int y = 0);

        Boom(Scene *sceneContext, int x, int y, sf::Texture *texture);

        ~Boom() override{}
    };

    class Preview : public GameObject {

        void UpdateDrawObjects() override;

        explicit Preview(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);

        explicit Preview(Scene *sceneContext);;

        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;

    public:
        explicit Preview(Scene *sceneContext, int x = 0, int y = 0);

        Preview(Scene *sceneContext, int x, int y, sf::Texture *texture);

        ~Preview() override{}
    };


    class Fly : public GameObject {
        void UpdateDrawObjects() override;

    public:
        bool available = true;
        float attack_point_x = 0;
        float attack_point_y = 0;

        void  Attack(float x, float y){
             available = false;
                SetPosition(x_position,y+35);
             attack_point_x = x;
             attack_point_y = y;
             state = State::FLY;
        }
        bool CanAttack(){
            if (x_position <= attack_point_x)
            {
                return true;
            }
            return  false;
        }
        bool Repair(){
            if (x_position <= -200)
            {
                state = State::STAY;
                available = true;
                return true;
            }
            return  false;
        }
        enum class State{
            STAY,FLY
        };

        State state = State::STAY;
        explicit Fly(Scene *sceneContext, const sf::Sprite& sprite1, int _x, int _y);
        explicit Fly(Scene *sceneContext, const sf::Texture& tex, int _x, int _y);

        explicit Fly(Scene *sceneContext);
        void SetPosition(float x, float y ) override;
        void MovePosition(float x, float y) override;
        explicit Fly(Scene *sceneContext, int x = 0, int y = 0);

        Fly(Scene *sceneContext, int x, int y, sf::Texture *texture);
        ~Fly() override{}

        void DoRapair(float _x_max);
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_OBJECTS_H
