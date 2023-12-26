//
// Created by OchiAnthropos on 23.12.2023.
//
#include "GamePlayScene.h"

namespace Game {
    GamePlayScene::GamePlayScene(Scene *_scene, int _y_size, int _x_size): SceneHolder(_scene, _y_size, _x_size)  { this->scene = _scene; }
    GamePlayScene::GamePlayScene(Scene *_scene, sf::RenderWindow *context, int _y_size, int _x_size) : SceneHolder(
            _scene, context, _y_size, _x_size) {
        this->scene = _scene;
        this->scene->windowContext = context;
        if (!font.loadFromFile(R"(C:\AmericanDemocracySimulator\fonts\Arial.ttf)" )) {}
        if (!infoMenuFont.loadFromFile(R"(C:\AmericanDemocracySimulator\fonts\CourierNew.ttf)" )) {}

        auto style_about_information = UI::TextInfos(&font,16, new sf::Color(1,0,0), 10, 10, sf::Text::Regular);
        style_about_information.includes->push_back(0);
        style_about_information.includes->push_back(1);
        style_about_information.includes->push_back(2);

        auto style_works = UI::TextInfos(&infoMenuFont, 16, new sf::Color(0,0,1), 10, 10, sf::Text::Regular);
        style_about_information.includes->push_back(3);
        style_about_information.includes->push_back(4);
        style_about_information.includes->push_back(5);

        auto style_works_info = UI::TextInfos(&infoMenuFont, 16, new sf::Color(0,1,0), 10, 10, sf::Text::Regular);
        style_about_information.includes->push_back(6);
        style_about_information.includes->push_back(7);
        style_about_information.includes->push_back(8);

        textInfos.push_back(style_about_information);
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
        CreatePool();
        CreateGround();
        LoadShipTexture();
        CreatePoint();
        CreateUI();

        addCCoroutineFunk("ship movement",  new Coroutine([this]() { MoveShips(); }, 0.06f) );
        addCCoroutineFunk("inspector logger",  new Coroutine([this]() { MoveShipLogger(); }, 15.0f) );
    }
    void GamePlayScene::Update()
    {
        SceneHolder::Update();
        if (this->scene->windowContext != nullptr) {mousePosition = sf::Mouse::getPosition(*this->scene->windowContext);}

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
        if (play)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution_y(20, x_size - 60);
            std::uniform_int_distribution<int> distribution_x(0, 25);

            sf::Vector2f newPosition;
            int x = distribution_x(gen);
            int y = distribution_y(gen);

            newPosition = sf::Vector2f((float) x, (float) y);
            if (!checkCollision(newPosition)) CreateShip(newPosition.x, newPosition.y);
        }
    }
    void GamePlayScene::MoveShips()
    {
        if (play) {
            for (auto ship: *active_ships)
            {
                ship->MovePosition(setting.ship_type_one_speed, 0);
                if (CheckShipOut(ship))
                {
                    dead = true;
                    start = false;
                    menu = false;
                    pause = false;
                    play = false;
                }
            }
        }
    }
    void GamePlayScene::MoveShipLogger() const {
        Debugger::Log(
                "play:" + std::to_string(play) + "\n" +
                "menu:"  + std::to_string(menu) + "\n" +
                "dead:"  + std::to_string(dead) + "\n" +
                "start:" + std::to_string(start) + "\n" +
                "pause:" + std::to_string(pause),
            Debugger::Color::YELLOW
            );
        Debugger::DebugInspector(scene->getObjects(), 3);
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
        GameObject::AllowAll(gr1);
        GameObject::AllowAll(gr2);
        scene->addObject(gr1, 2);
        scene->addObject(gr2, 2);
    }
    void GamePlayScene::LoadShipTexture()
    {
        if (!shipTexture.loadFromFile(setting.ship_type_one_path))
            std::cout << "Error loading texture!" << std::endl;
        shipSprite.setTexture(shipTexture);
        shipSprite.setTextureRect(sf::IntRect(0, 0, (int)setting.ship_type_one_width, (int)setting.ship_type_one_height));
    }
    void GamePlayScene::CreateShip(float x = 0 , float y = 0) const
    {
        auto* ship = new Objects::Ship(scene,shipSprite,0 ,0);
        ship->SetPosition(x, y);
        ship->Allow(std::vector<GameState> {GameState::Play});
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
    GamePlayScene::GamePlayScene() = default;
    bool GamePlayScene::CheckShipOut(Game::Objects::Ship *ship) const
    {
        return std::any_of(active_ships->begin(), active_ships->end(), [this](Objects::Ship *ship) {
            float ship_right = ship->x_position + ship->width;
            return ship_right <= x_size - 50;
        });
    }

    void GamePlayScene::CreateUI()
    {
        //  load assets


        if (!Panel.loadFromFile(R"(C:\AmericanDemocracySimulator\textures\panel.png)" )) {}
        if (!Button.loadFromFile(R"(C:\AmericanDemocracySimulator\textures\button.png)" )) {}
        // position
        panel = new UI::BaseUIObject(x_size/2 - 200/2,y_size/2 -250/2 ,scene);
        info = new UI::BaseUIObject( 190, 15,scene);

        but_start = new UI::Button(50,20,panel,scene, new UI::UIRectangle(0,0,30,100));
        but_info = new UI::Button(50,60,panel,scene, new UI::UIRectangle(0,0,30,100));
        but_come_to_menu = new UI::Button(50,60, panel,scene, new UI::UIRectangle(0,0,30,100));
        but_end = new UI::Button(50,190, panel,scene, new UI::UIRectangle(0,0,30,100));
        //
        // setting panel
        panel->SetByTexture(&Panel, 200, 250);

        but_start->SetText("START", &font,20,textColor,14,3,sf::Text::Bold);
        but_start->SetByTexture(&Button, 100, 30);

        but_end->SetText("END",&font,20,textColor,14,3,sf::Text::Bold);
        but_end->SetByTexture(&Button, 100, 30);

        but_info->SetText("INFO-MENU",&font,15,textColor,3,6,sf::Text::Bold);
        but_info->SetByTexture(&Button, 100, 30);

        but_come_to_menu->SetText("MAIN-MENU",&font,15,textColor,3,6,sf::Text::Bold);
        but_come_to_menu->SetByTexture(&Button, 100, 30);
        //

        int index = 0;
        for (auto draw : textInfos){
            for (int include_index : *draw.includes){
                auto *dr = new UI::BaseUIObject(210, 20*  (float)index ,scene);
                dr->SetText(setting.information[include_index],&font,15,textColor,3,6,sf::Text::Bold);
                texts->push_back(dr);
                index++;
            }
        }


        but_start->SetRect();
        but_end->SetRect();
        but_info->SetRect();
        but_come_to_menu->SetRect();
        // event
        but_start->onClick = [this]() { OnStartClickedUI(); };
        but_end->onClick = [this]() { OnEndClickedUI(); };
        but_info->onClick = [this]() { OnInfoClickedUI(); };
        but_come_to_menu->onClick = [this]() { OnComeBackToStartClickedUI(); };
        // add to collision handle
        UIActive->push_back(but_end);
        UIActive->push_back(but_start);
        UIActive->push_back(but_info);
        UIActive->push_back(but_come_to_menu);

        // score text
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
        Debugger::Log("Start Play");
        this->scene->currentState = GameState::Play;
        play = true;

        dead = false;
        start = false;
        menu = false;
        pause = false;
    }

    void GamePlayScene::OnInfoClickedUI()
    {
        Debugger::Log("Info Menu");
        panel->SetPosition(setting.panelUIPositionXDefault, setting.panelUIPositionYDefault);

        this->scene->currentState = GameState::Menu;
        menu = true;

        dead = false;
        start = false;
        pause = false;
        play = false;
    }

    void GamePlayScene::OnComeBackToStartClickedUI(){
        Debugger::Log("Come Back");
        panel->SetPosition(x_size/2 - 200/2,y_size/2 -250/2);

        this->scene->currentState = GameState::Start;
        start = true;

        dead = false;
        menu = false;
        pause = false;
        play = false;
    }

    void GamePlayScene::OnEndClickedUI()
    {
        Debugger::Log("End Game");
        this->scene->currentState = GameState::Default;
        dead = false;
        start = false;
        menu = false;
        pause = false;
        play = false;
    }

    void GamePlayScene::CheckUICollision()
    {
        for (auto* UIActiveObj : *UIActive)
        {
            if (UIActiveObj->CheckCollision((float)UIposition.x,(float)UIposition.y))
            {
                if (UIActiveObj->activation)
                {
                    UIActiveObj->onClick();
                    break;
                }
            }
        }
    }

    void GamePlayScene::TOStart()
    {

        but_come_to_menu->activation = false;
        but_start->activation = true;
        but_info->activation = true;
        but_end->activation = true;
        but_start->SetRect();
        but_info->SetRect();
        but_end->SetRect();

        panel->DrawHimself();

        but_start->DrawHimself();
        but_info->DrawHimself();
        but_end->DrawHimself();
    }

    void GamePlayScene::TOPlay()
    {
        but_come_to_menu->activation = false;
        but_start->activation = false;
        but_info->activation = false;
        but_end->activation = false;

        addCCoroutineFunk("generator",  new Coroutine([this]() { GenerateRandomPosition(); }, 3.0f, 6.0f, 3.0f)  );
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




        panel->DrawHimself();

        but_start->DrawHimself();
        but_come_to_menu->DrawHimself();
        but_end->DrawHimself();
        info->DrawHimself();
        for (auto dr : *texts){
            dr->DrawHimself();
        };
//        about->DrawHimself();
    }
}