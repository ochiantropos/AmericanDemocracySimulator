//
// Created by OchiAnthropos on 23.12.2023.
//
#include "GamePlayScene.h"

namespace Game {

    GamePlayScene::GamePlayScene() = default;
    GamePlayScene::GamePlayScene(Scene *_scene, int _y_size, int _x_size): SceneHolder(_scene, _y_size, _x_size)  { this->scene = _scene; }
    GamePlayScene::GamePlayScene(Scene *_scene, sf::RenderWindow *context, int _y_size, int _x_size) : SceneHolder(
            _scene, context, _y_size, _x_size) {
        this->scene = _scene;
        this->scene->windowContext = context;
        if (!deadShip->loadFromFile(setting.GetPath(setting.animationSettings.DeadPath))) {}
        if (!BOOOOOM->loadFromFile(setting.GetPath(setting.animationSettings.BoomPath ))) {}
        if (!Panel.loadFromFile(setting.panel)) {}
        if (!Button.loadFromFile(setting.button )) {}
        if (!InfoPanel.loadFromFile(setting.infoPanel )) {}
        if (!EndButtonTexture.loadFromFile(setting.EndButton )) {}
        if (!previewTexture.loadFromFile(setting.animationSettings.PPath )) {}
        if (!TextTexture.loadFromFile(setting.panelText )) {}
        if (!font.loadFromFile(setting.GetPath( setting.fontSettings.baseFont ) )) {}
        if (!infoMenuFont.loadFromFile(setting.GetPath(setting.fontSettings.informationFont ) )) {}
        if (!infoHeaderMenuFont.loadFromFile(setting.GetPath( setting.fontSettings.informationHeaderFont) )) {}
        if (!flyText.loadFromFile(setting.GetPath( setting.flyTex) )) {}
        CreatePool();
        CreateGround();
        LoadShipTexture();
        CreatePoint();
        CreateFly();
        auto coll_header = new sf::Color(1,0,1);
        auto coll_info = new sf::Color(1,1,0);

        auto style_about_information = UI::TextInfos(&infoHeaderMenuFont,15, coll_header, 10, 10, sf::Text::Regular);
        style_about_information.includes->push_back(0);
        style_about_information.includes->push_back(1);
        style_about_information.includes->push_back(6);

        auto style_about_information_link = UI::TextInfos(&infoMenuFont,15, coll_info, 10, 10, sf::Text::Regular);
        style_about_information_link.includes->push_back(2);
        style_about_information_link.includes->push_back(3);
        style_about_information_link.includes->push_back(4);
        style_about_information_link.includes->push_back(5);

        auto style_works = UI::TextInfos(&infoHeaderMenuFont, 15, coll_header, 10, 10, sf::Text::Regular);
        style_works.includes->push_back(7);
        style_works.includes->push_back(13);
        style_works.includes->push_back(18);

        auto style_works_role = UI::TextInfos(&infoMenuFont, 15, coll_header, 10, 10, sf::Text::Regular);
        style_works_role.includes->push_back(8);
        style_works_role.includes->push_back(14);
        style_works_role.includes->push_back(19);

        auto style_works_info = UI::TextInfos(&infoMenuFont, 15, coll_info, 10, 10, sf::Text::Regular);
        style_about_information.includes->push_back(10);
        style_about_information.includes->push_back(11);
        style_about_information.includes->push_back(12);
        style_about_information.includes->push_back(16);
        style_about_information.includes->push_back(17);
        style_about_information.includes->push_back(21);
        style_about_information.includes->push_back(22);
        style_about_information.includes->push_back(23);
        style_about_information.includes->push_back(24);

        auto style_works_info_date = UI::TextInfos(&infoHeaderMenuFont, 15, coll_info, 10, 10, sf::Text::Regular);
        style_works_info_date.includes->push_back(9);
        style_works_info_date.includes->push_back(15);
        style_works_info_date.includes->push_back(20);

        textInfos.push_back(style_about_information_link);
        textInfos.push_back(style_about_information);
        textInfos.push_back(style_works_role);
        textInfos.push_back(style_works_info_date);
        textInfos.push_back(style_works);
        textInfos.push_back(style_works_info);
    }
    void GamePlayScene::OnClickedEnd()
    {
        SceneHolder::OnClickedEnd();
        pointObject->baseAnimation->x = -100;
        pointObject->baseAnimation->y = -100;
        pointObject->baseAnimation->sprite.setPosition(-100,-100);
        CheckUICollision();
        if (scene->currentState == GameState::Play){Attack();};
    }
    void GamePlayScene::OnClicked()
    {
        SceneHolder::OnClicked();
        pointObject->baseAnimation->x = (float)mousePosition.x - setting.animationSettings.PointWidth/2;
        pointObject->baseAnimation->y = (float)mousePosition.y - setting.animationSettings.PointHeight/2;
    }
    void GamePlayScene::OnClickedStart()
    {
        UIposition = mousePosition;
        SceneHolder::OnClickedStart();
        pointObject->baseAnimation->x = (float)mousePosition.x  - setting.animationSettings.PointWidth/2;
        pointObject->baseAnimation->y = (float)mousePosition.y  - setting.animationSettings.PointHeight/2;
    }
    void GamePlayScene::Start()
    {
        SceneHolder::Start();
        CreateUI();
        preview = new Objects::Preview(scene,0,0,&previewTexture);
        preview->Allow(GameState::Preview);
//        addCCoroutineFunk("ship movement",   shipMover);
        addCCoroutineFunk("inspector logger", inspectorDebugger);
    }
    void GamePlayScene::Update()
    {
        SceneHolder::Update();
        if (Session_Time < 4)
        {
            if (Session_Time > 1 && preview_start) {preview_start = false; scene->addObject(preview,1); }
            dead = false;
            start = false;
            menu = false;
            pause = true;
            play = false;
        } else {
            if (scene->currentState == GameState::Preview) {
                preview->deletable = true;
                dead = false;
                start = true;
                menu = false;
                pause = false;
                play = false;
                scene->currentState = GameState::Start;
            }
        }
        Session_Time += deltaTime;
        if (this->scene->windowContext != nullptr)
        {
            mousePosition = sf::Mouse::getPosition(*this->scene->windowContext);
        }
        if (scene->currentState == GameState::Play){
            TryToClear();
            MoveShips();
            for (auto fly : flies){
                if (!fly->available){
                    fly->MovePosition(-200.0f * deltaTime,0);
                    if (!fly->Repair()){
                        if (fly->CanAttack())
                        {
                            Boom(fly->attack_point_x, fly->attack_point_y);
                        }
                    } else {
                        fly->DoRapair(x_size);
                    }
                }
            }
            Game_Time += deltaTime;
        }
        else
        {
            if (Game_Time != 0) // out of play
            {
                last_game_time = Game_Time;
                last_kill_ship = Game_Kill;
                Game_Kill = 0;
                Game_Time = 0;
                for (auto* ship: *active_ships)ship->deletable = true;
                active_ships->clear();
                for (auto* boom: *active_boom)boom->deletable = true;
                active_boom->clear();
                for (auto* dead_ship: *active_ships_dead)dead_ship->deletable = true;
                active_ships_dead->clear();
            }
        }
    }
    bool GamePlayScene::checkCollision(const sf::Vector2f &newPos) const
    {
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
    void GamePlayScene::GenerateRandomPosition() const
    {
        if (scene->currentState == GameState::Play)
        {

            Debugger::Log("",Debugger::Color::DARK_GREEN);
            std::random_device rd;
            std::mt19937 gen1(rd());
            std::mt19937 gen2(rd());

            std::uniform_int_distribution<int> distribution_y(20, y_size -40);
            std::uniform_int_distribution<int> distribution_x(40, 60);
            sf::Vector2f newPosition;
            int y = distribution_y(gen1);
            int x = -distribution_x(gen2);

            newPosition = sf::Vector2f((float) x, (float) y);
            if (!checkCollision(newPosition)) {
                CreateShip(newPosition.x, newPosition.y);
            }
        }
    }
    void GamePlayScene::MoveShips()
    {
        if (play) {
            for (auto ship: *active_ships)
            {
                if (!ship->deletable) {
                    ship->MovePosition(setting.ship_type_one_speed * deltaTime*5, 0);

                    if (CheckShipOut(ship)){
                        scene->currentState == GameState::Start;
                        last_kill_ship = Game_Kill;
                        Game_Kill = 0;
                        last_game_time= Game_Time;
                        Game_Time = 0;
                        dead = false;
                        start = true;
                        menu = false;
                        pause = false;
                        play = false;
                    }
                }
            }
        }
    }
    void GamePlayScene::MoveShipLogger() const {
        Debugger::Log(
                "[GAME][UI]  play:" + std::to_string(play) + "\t" +
                "menu:"  + std::to_string(menu) + "\t" +
                "dead:"  + std::to_string(dead) + "\t" +
                "start:" + std::to_string(start) + "\t" +
                "pause:" + std::to_string(pause),
            Debugger::Color::DARK_YELLOW
            );
        Debugger::DebugInspector(scene->getObjects(), 10);
    }
    void GamePlayScene::CreatePool() const
    {
        for (int x = 0; x <= (int)((float)x_size/setting.animationSettings.WaterPoolWidth); x++)
            for (int y = 0; y <= (int)((float)y_size/setting.animationSettings.WaterPoolHeight); y++)
            {
                auto* _pool = new Objects::WaterPool(scene, (int)(setting.animationSettings.WaterPoolWidth * (float)x), (int)(setting.animationSettings.WaterPoolHeight * (float)y));
                GameObject::AllowAll(_pool);
                scene->addObject(_pool,1);
            }
    }
    void GamePlayScene::CreateGround() const
    {
        auto * gr1 = new Objects::Ground(scene, x_size  -55,  (int)(setting.animationSettings.GroundAnimationHeight* (float)0 ));
        auto * gr2 = new Objects::Ground(scene, x_size  -55,  (int)(setting.animationSettings.GroundAnimationHeight* (float)1 ));
        auto * gr3 = new Objects::Ground(scene, x_size  -55,  (int)(setting.animationSettings.GroundAnimationHeight* (float)2 ));
        GameObject::AllowAll(gr1);
        GameObject::AllowAll(gr2);
        GameObject::AllowAll(gr3);
        scene->addObject(gr1, 2);
        scene->addObject(gr2, 2);
        scene->addObject(gr3, 2);
    }
    void GamePlayScene::LoadShipTexture()
    {
        if (!shipTexture.loadFromFile(setting.ship_type_one_path))
            Debugger::Log("Error loading shipTexture texture!", Debugger::Color::RED);
        shipSprite.setTexture(shipTexture);
        shipSprite.setTextureRect(sf::IntRect(0, 0, (int)setting.ship_type_one_width, (int)setting.ship_type_one_height));
    }
    void GamePlayScene::CreateShip(float x = 0 , float y = 0) const
    {
        auto* ship = new Objects::Ship(scene,shipSprite,0 ,0);
        ship->SetPosition(x, y);
        ship->Allow(GameState::Play);
        active_ships->push_back(ship);
        scene->addObject(ship,3);
    }
    void GamePlayScene::CreatePoint() {
        pointObject = new Objects::Point(scene, (int)(setting.animationSettings.PointWidth), (int)(setting.animationSettings.PointHeight));
        pointObject->x_position = -100;
        pointObject->y_position = -100;
        pointObject->baseAnimation->x = -100;
        pointObject->baseAnimation->y = -100;
        pointObject->sprite.setPosition(-100,-100);
        pointObject->Allow(std::vector<GameState> {GameState::Play});
        scene->addObject(pointObject,4);
    }
    bool GamePlayScene::CheckShipOut(Game::Objects::Ship *ship) const
    {
        return std::any_of(active_ships->begin(), active_ships->end(), [this](Objects::Ship *ship) {
            float ship_right = ship->x_position + ship->width;
            return ship_right >= (float)x_size - 90;
        });
    }
    void GamePlayScene::CreateUI()
    {
        // Base
        panel = new UI::BaseUIObject((float)x_size/2 - 200.0f/2,(float)y_size/2 -250.0f/2 ,scene);
        infoPanel = new UI::BaseUIObject(190,-18,scene);
        info = new UI::BaseUIObject( 190, 15,scene);
        LastGameTime = new UI::BaseUIObject(20,100,panel,scene);
        KillShip = new UI::BaseUIObject(20, 140,panel,scene);
        // Buttons
        but_start = new UI::Button(50,20,panel,scene, new UI::UIRectangle(0,0,30,100));
        but_info = new UI::Button(50,60,panel,scene, new UI::UIRectangle(0,0,30,100));
        but_come_to_menu = new UI::Button(50,60, panel,scene, new UI::UIRectangle(0,0,30,100));
        but_end = new UI::Button(50,190, panel,scene, new UI::UIRectangle(0,0,30,100));
        but_end_in_play = new UI::Button( (float)x_size - 200,35, scene,new UI::UIRectangle(0,0,35,95));
//        EndButtonTexture
        // setting panel
        panel->SetByTexture(&Panel, 200, 250);
        infoPanel->SetByTexture(&InfoPanel, 590, 590);
        // set Buttons
        but_start->SetText("START", &font,20,textColor,14,3,sf::Text::Bold);
        but_start->SetByTexture(&Button, 100, 30);
        //
        but_end->SetText("END",&font,20,textColor,14,3,sf::Text::Bold);
        but_end->SetByTexture(&Button, 100, 30);
        //
        but_info->SetText("INFO-MENU",&font,15,textColor,3,6,sf::Text::Bold);
        but_info->SetByTexture(&Button, 100, 30);
        //
        but_end_in_play->SetText("End Game",&font,15,textColor,3,6,sf::Text::Bold);
        but_end_in_play->SetByTexture(&EndButtonTexture, 95, 35);
        //
        but_come_to_menu->SetText("MAIN-MENU",&font,15,textColor,3,6,sf::Text::Bold);
        but_come_to_menu->SetByTexture(&Button, 100, 30);
        // set text information
        int index = 0;
        for (auto draw : textInfos){
            for (int include_index : *draw.includes){
                auto *dr = new UI::BaseUIObject(210, 20*  (float)include_index ,scene);
                dr->SetText(setting.information[include_index],draw.font,draw.size,draw.col,draw.x,draw.y,draw.style);
                texts->push_back(dr);
                index++;
            }
        }
        // score text
        KillShip->SetByTexture(&TextTexture,160,30);
        KillShip->SetText("Score: ",&infoHeaderMenuFont,16,textScoreColor,40,6,sf::Text::Bold);
        LastGameTime->SetByTexture(&TextTexture,160,30);
        LastGameTime->SetText("Game Time: ",&infoHeaderMenuFont,16,textScoreColor,30,6,sf::Text::Bold);
        // change rect menu
        but_start->SetRect();
        but_end->SetRect();
        but_info->SetRect();
        but_come_to_menu->SetRect();
        but_end_in_play->SetRect();
        // event
        but_start->onClick = [this]() { OnStartClickedUI(); };
        but_end->onClick = [this]() { OnEndClickedUI(); };
        but_info->onClick = [this]() { OnInfoClickedUI(); };
        but_come_to_menu->onClick = [this]() { OnComeBackToStartClickedUI(); };
        but_end_in_play->onClick = [this]() { OnEndGame();};
        // add to collision handle
        UIActive->push_back(but_end);
        UIActive->push_back(but_start);
        UIActive->push_back(but_info);
        UIActive->push_back(but_come_to_menu);
        UIActive->push_back(but_end_in_play);
    }
    void GamePlayScene::DrawUI()
    {
        if (start && !(play||pause||dead||menu))
            TOStart();
        if (play && !(start||pause||dead||menu))
            TOPlay();
        else if (pause && !(start||play||dead||menu))
            TOPause();
        else if (dead && !(start||play||pause||menu))
            TODead();
        else if (menu && !(start||play||pause||dead))
        {
            TOMenu();
        }
    }
    void GamePlayScene::OnStartClickedUI()
    {
        Debugger::Log("[GAME][UI] Start Play", Debugger::Color::DARK_YELLOW);
        this->scene->currentState = GameState::Play;
        play = true;

        dead = false;
        start = false;
        menu = false;
        pause = false;
        generator = new Coroutine([this]() { GenerateRandomPosition(); }, 2.0f,6.0f,1.0f);
        addCCoroutineFunk("generator",   generator); // start ship generator
    }
    void GamePlayScene::OnInfoClickedUI()
    {
        Debugger::Log("[GAME][UI] Info Menu", Debugger::Color::DARK_YELLOW);
        panel->SetPosition(setting.panelUIPositionXDefault, setting.panelUIPositionYDefault);
        LastGameTime->SetPosition(20,100);
        KillShip->SetPosition(20,140);
        this->scene->currentState = GameState::Menu;
        menu = true;

        dead = false;
        start = false;
        pause = false;
        play = false;
    }
    void GamePlayScene::OnComeBackToStartClickedUI(){
        Debugger::Log("[GAME][UI] Come Back", Debugger::Color::DARK_YELLOW);
        panel->SetPosition(x_size/2 - 200/2,y_size/2 -250/2);
        LastGameTime->SetPosition(20,100);
        KillShip->SetPosition(20,140);
        this->scene->currentState = GameState::Start;
        start = true;

        dead = false;
        menu = false;
        pause = false;
        play = false;
    }
    void GamePlayScene::OnEndClickedUI()
    {
        Debugger::Log("[GAME][UI] End Game",Debugger::Color::CYAN);
        this->scene->currentState = GameState::Default;
        dead = false;
        start = false;
        menu = false;
        pause = false;
        play = false;
        std::exit(EXIT_SUCCESS);
    }
    void GamePlayScene::OnEndGame() {
        Debugger::Log("[GAME] End Game Iter",Debugger::Color::DARK_RED);

        OnComeBackToStartClickedUI();
    }
    void GamePlayScene::CheckUICollision()
    {
        for (auto* UIActiveObj : *UIActive)
            if (UIActiveObj->CheckCollision((float)UIposition.x,(float)UIposition.y))
                if (UIActiveObj->activation)
                {
                    UIActiveObj->onClick();
                    break;
                }
    }
    void GamePlayScene::TOStart()
    {
        but_come_to_menu->activation = false;
        but_start->activation = true;
        but_info->activation = true;
        but_end_in_play->activation = false;
        but_end->activation = true;
        but_start->SetRect();
        but_info->SetRect();
        but_end->SetRect();
        panel->DrawHimself();
        // text score setting
        KillShip->text->setString("Score : " + std::string(std::to_string( (int)last_kill_ship ) ));
        LastGameTime->text->setString(
                std::string("Time : ") +
                std::string(std::to_string( ((int(last_game_time*100))/100) ) ) +
                std::string( "." ) +
                std::string(std::to_string( ((int(last_game_time*100))%100) ) ) +
                std::string( " s" ));
        // draw on panel
        LastGameTime->DrawHimself();
        KillShip->DrawHimself();
        but_start->DrawHimself();
        but_info->DrawHimself();
        but_end->DrawHimself();
        //
    }
    void GamePlayScene::TOPlay()
    {
        but_come_to_menu->activation = false;
        but_start->activation = false;
        but_info->activation = false;
        but_end_in_play->activation = true;
        but_end->activation = false;
        but_end_in_play->SetRect();
        but_end_in_play->DrawHimself();
    }
    void GamePlayScene::TOPause()
    {
    }
    void GamePlayScene::TODead()
    {
        TOStart();
    }
    void GamePlayScene::TOMenu() {
        but_start->SetRect();
        but_come_to_menu->SetRect();
        but_end->SetRect();

        but_info->activation = false;
        but_come_to_menu->activation = true;
        but_start->activation = true;
        but_end->activation = true;
        but_end_in_play->activation = false;
// text score setting
        KillShip->text->setString("Score : " + std::string(std::to_string( (int)last_kill_ship ) ));
        LastGameTime->text->setString(
                std::string("Time : ") +
                std::string(std::to_string( ((int(last_game_time*100))/100) ) ) +
                std::string( "." ) +
                std::string(std::to_string( ((int(last_game_time*100))%100) ) ) +
                std::string( " s" ));
        panel->DrawHimself();
        infoPanel->DrawHimself();
        but_start->DrawHimself();
        but_come_to_menu->DrawHimself();
        but_end->DrawHimself();
        info->DrawHimself();
        LastGameTime->DrawHimself();
        KillShip->DrawHimself();
        for (auto dr : *texts){dr->DrawHimself();};
    }
    void GamePlayScene::Attack()
    {
        if (Game_Time >0.2f)
        {
            for (auto fly : flies){
                if (fly->available)
                {
                    fly->Attack((float)mousePosition.x-78,(float)mousePosition.y-35);
                    break;
                }
            }
        }
    }
    void GamePlayScene::TryToClear() {
        active_ships->erase(std::remove_if(active_ships->begin(), active_ships->end(), [](Objects::Ship* value) {
            return  value->deletable;// Удаляем все значения больше порогового значения
        }), active_ships->end());
        active_boom->erase(std::remove_if(active_boom->begin(), active_boom->end(), [](Objects::Boom* value) {
            return  value->deletable;// Удаляем все значения больше порогового значения
        }), active_boom->end());
        scene->Clear();
    }
    void GamePlayScene::ClearTheBoom() {
        if (active_boom == nullptr) return;
    }
    void GamePlayScene::FindCollision(float x, float y) {

        for (auto gameObject : *active_ships) {
            float shipX = gameObject->x_position;
            float shipY = gameObject->y_position;
            float shipLength = 100; // Довжина корабля
            float shipWidth = 30;   // Ширина корабля
            if (IColliderCompare::CheckCollisionCircleRectangle(x, y, 50, shipX, shipY, shipWidth, shipLength)) {
                CreateDeadAnimation(gameObject->x_position, gameObject->y_position);
                Game_Kill++;
                gameObject->deletable = true;
            }
        }
    }
    void GamePlayScene::CreateDeadAnimation(float x, float y) {
        auto* templateDeadShip = new Objects::DeadShip(scene, (int)x, (int)y, deadShip);
        templateDeadShip->Allow(GameState::Play);
        scene->addObject(templateDeadShip,7);
        active_ships_dead->push_back(templateDeadShip);
    }
    void GamePlayScene::CreateFly() {
        flies.push_back(new Objects::Fly(scene,flyText, x_size+200,100));
        flies.push_back(new Objects::Fly(scene,flyText, x_size+200,300));
        flies.push_back(new Objects::Fly(scene,flyText, x_size+200,300));
        flies[0]->gameObjectName = "Fly 1";
        flies[1]->gameObjectName = "Fly 2";
        flies[2]->gameObjectName = "Fly 3";

        flies[0]->Allow(GameState::Play);
        flies[1]->Allow(GameState::Play);
        flies[2]->Allow(GameState::Play);
        scene->addObject(flies[0], 8);
        scene->addObject(flies[1], 8);
        scene->addObject(flies[2], 8);
    }
    void GamePlayScene::Boom(float x, float y) {
        auto* templateBoom = new Objects::Boom(scene, x, y,BOOOOOM);
        templateBoom->Allow(GameState::Play);
        scene->addObject(templateBoom, 6);
        active_boom->push_back(templateBoom);
        FindCollision(x, y );
    }
}