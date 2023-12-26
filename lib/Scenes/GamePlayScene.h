//
// Created by OchiAnthropos on 23.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#define AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
#pragma once
#include "../Objects/Objects.h"
#include "../../Settings/GamePlaySceneSettings.h"
#include "../Architect/Base/Base.h"
#include "../UI/UI.h"

namespace Game {

    class GamePlayScene : public SceneHolder {
        GamePlayScenesSetting setting = GamePlayScenesSetting();

    protected:

        std::vector<UI::TextInfos> textInfos =std::vector<UI::TextInfos>();
        std::vector<UI::BaseUIObject*> *texts = new std::vector<UI::BaseUIObject*>();;
        bool start = true;

        bool dead = false;
        bool pause = false;

        bool play = false;
        bool menu = false;

        Objects::Point *pointObject;

        sf::Vector2<int> UIposition = {0,0};
        sf::Color *textColor = new sf::Color(107,236,255);
        sf::Sprite shipSprite;
        sf::Texture shipTexture;
        sf::Sprite shipType2Sprite;
        sf::Texture shipType2Texture;
        sf::Font font;
        sf::Font infoMenuFont;
        sf::Texture Panel = sf::Texture();;
        sf::Texture Button = sf::Texture();

        UI::BaseUIObject *panel;
        UI::BaseUIObject *info;

        UI::Button *but_start;
        UI::Button *but_end;
        UI::Button *but_info;
        UI::Button *but_come_to_menu;

        std::vector<Objects::WaterPool> pool;
        std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();
        std::vector<UI::Button*> *UIActive = new  std::vector<UI::Button*>();

        void CreatePool() const;
        void CreateGround() const;
        void LoadShipTexture();
        void CreateShip(float x, float y) const;
        // patch -1-0-3.4
        void MoveShipLogger() const;
        void MoveShips();
        void GenerateRandomPosition() const;
        bool checkCollision(const sf::Vector2f& newPos) const;
        // patch -1-2-1
        void CreatePoint();

    public:
            GamePlayScene();
            GamePlayScene(Scene *_scene, int _y_size, int _x_size);
            GamePlayScene(Scene *_scene,sf::RenderWindow *context, int _y_size, int _x_size);
            // Game cicle
            void OnClicked() override;
            void OnClickedStart() override;
            void OnClickedEnd() override;
            // overriding
            void Update() override;
            void Start() override;
            void CreateUI() override;
            void CheckUICollision() override;
            void DrawUI() override;
            //  UI
            void OnStartClickedUI();
            void OnEndClickedUI();
            void OnInfoClickedUI();
            // -- game logic c-set
            bool CheckShipOut(Objects::Ship *ship) const;

        void TOStart();
        void TOPlay();
        void TOPause();
        void TODead();

        void TOMenu();

        void OnComeBackToStartClickedUI();
    };
} // Game
#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
