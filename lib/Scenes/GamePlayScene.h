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
    private:
        GamePlayScenesSetting setting = GamePlayScenesSetting();
    protected:
        // UI TYPE RENDER STATUS
        bool start = true;
        bool dead = false;
        bool pause = false;
        bool play = false;
        bool menu = false;
        //
        bool preview_start;
        float Session_Time = 0;
        float Game_Time = 0;
        int Game_Kill = 0;
        float current_expand = 1;
        //
        sf::Vector2<int> UIposition = {0,0};
        sf::Color *textColor = new sf::Color(107,236,255);
        sf::Color *textScoreColor = new sf::Color(122,0,237);
        Coroutine *generator;
        Coroutine *shipMover =  new Coroutine([this]() { MoveShips(); }, 0.06f);
        Coroutine *inspectorDebugger =   new Coroutine([this]() { MoveShipLogger(); }, 5.0f);
        // game objects
        std::vector<Objects::WaterPool> pool;
        std::vector<Objects::Fly*> flies;
        std::vector<Objects::Ship*> *active_ships = new std::vector<Objects::Ship*>();
        std::vector<Objects::Boom*> *active_boom = new std::vector<Objects::Boom*>();
        std::vector<Objects::DeadShip*> *active_ships_dead = new std::vector<Objects::DeadShip*>();
        std::vector<UI::Button*> *UIActive = new  std::vector<UI::Button*>();
        Objects::Point *pointObject;
        Objects::Preview *preview;
        // UI elements
        sf::Texture Panel = sf::Texture();;
        sf::Texture Button = sf::Texture();
        sf::Texture InfoPanel = sf::Texture();
        sf::Texture shipTexture = sf::Texture();
        sf::Texture EndButtonTexture = sf::Texture();
        sf::Texture shipType2Texture = sf::Texture();
        sf::Texture TextTexture = sf::Texture();
        sf::Texture previewTexture = sf::Texture();
        sf::Texture flyText = sf::Texture();
        sf::Texture *deadShip = new  sf::Texture();
        sf::Texture *BOOOOOM = new  sf::Texture();
        sf::Sprite shipType2Sprite;
        sf::Sprite shipSprite;
        sf::Font infoHeaderMenuFont;
        sf::Font infoMenuFont;
        sf::Font font;
        // UI OBJECTS
        UI::BaseUIObject *infoPanel;
        UI::BaseUIObject *panel;
        UI::BaseUIObject *info;
        UI::Button *but_start;
        UI::Button *but_end;
        UI::Button *but_info;
        UI::Button *but_come_to_menu;
        UI::Button *but_end_in_play;
        std::vector<UI::TextInfos> textInfos =std::vector<UI::TextInfos>();
        std::vector<UI::BaseUIObject*> *texts = new std::vector<UI::BaseUIObject*>();;
        int last_kill_ship = 0;
        UI::BaseUIObject *KillShip;
        float last_game_time = 0;
        UI::BaseUIObject *LastGameTime;
        // FUNCTIONALITY
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
            //  UI
            void CreateUI() override;
            void CheckUICollision() override;
            void DrawUI() override;
            /// UI button actions
            void OnStartClickedUI();
            void OnEndClickedUI();
            void OnInfoClickedUI();
            void OnComeBackToStartClickedUI();
            void OnEndGame();
            // -- game logic c-set
            bool CheckShipOut(Objects::Ship *ship) const;
            // UI update drawer
        void TOStart();
        void TOPlay();
        void TOPause();
        void TODead();
        void TOMenu();
        // attack action caller
        void Attack();
        // clear temp element like Boom animation and other
        void TryToClear();
        void ClearTheBoom();
        void ClearTheShipDead();
        // other funk in attack processing
        void FindCollision(float x, float y);
        void CreateDeadAnimation(float x, float y);

        void CreateFly();

        void Boom();

        void Boom(float x, float y);
    };
} // Game
#endif //AMERICANDEMOCRACYSIMULATOR_GAMEPLAYSCENE_H
