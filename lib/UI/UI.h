//
// Created by OchiAnthropos on 26.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_UI_H
#define AMERICANDEMOCRACYSIMULATOR_UI_H

#include "../Architect/Architect.h"

namespace Game::UI
{
    class IUICollision{
        virtual  bool CheckCollision(float x, float y){ return false;}
    };
    class UIRect {
    public:
        float x_pos = 0;
        float y_pos = 0;
        virtual bool CollidePoint(float x, float y) { return false; }
        UIRect(float x, float y) : x_pos(x), y_pos(y) {}
        UIRect() = default;
    };
    class UIRectangle : public UIRect {
    public:
        float height = 0;
        float width = 0;
        UIRectangle(float x, float y, float h, float w) : UIRect(x, y), height(h), width(w) {}
        bool CollidePoint(float x, float y) override {
            return (x >= x_pos && x <= x_pos + width && y >= y_pos && y <= y_pos + height);
        }
    };
    class UICircle : public UIRect {
    public:
        explicit UICircle(float x, float y, float radius) : UIRect(x, y), radius(radius) {}

        bool CollidePoint(float x, float y) override {
            return std::sqrt(std::pow(x - x_pos, 2) + std::pow(y - y_pos, 2)) <= radius;
        }
    protected:
        float radius;
    };
    class Ellipse : public UIRect {
    public:
        Ellipse(float x, float y, float horizontalRadius, float verticalRadius) : UIRect(x, y), horizontalRadius(horizontalRadius), verticalRadius(verticalRadius) {}
        bool CollidePoint(float x, float y) override {
            float normalizedX = (x - x_pos) / horizontalRadius;
            float normalizedY = (y - y_pos) / verticalRadius;
            return (std::pow(normalizedX, 2) + std::pow(normalizedY, 2)) <= 1.0f;
        }
    protected:
        float horizontalRadius;
        float verticalRadius;
    };

    class RoundedRectangle : public UIRect {
    public:
        float height = 0;
        float width = 0;
        float radius = 0;

        RoundedRectangle(float x, float y, float h, float w, float r) : UIRect(x, y), height(h), width(w), radius(r) {}

        bool CollidePoint(float x, float y) override {
            if (y >= y_pos && y <= y_pos + radius && x >= x_pos && x <= x_pos + width) return true;
            if (y >= y_pos + height - radius && y <= y_pos + height && x >= x_pos && x <= x_pos + width) return true;
            if (x >= x_pos && x <= x_pos + radius && y >= y_pos && y <= y_pos + height) return true;
            if (x >= x_pos + width - radius && x <= x_pos + width && y >= y_pos && y <= y_pos + height) return true;
            return false;
        }
    };

    class BaseUIObject{
    protected:
        sf::Sprite *spriteRender = new sf::Sprite();
        Scene *context = nullptr;
        BaseUIObject *anchor = nullptr;
        std::string textString = "BaseUIObject";

    public:
        virtual void SetDrawObject(){
            if (text != nullptr) text->setPosition(this->x + x_width_text,this->y + y_height_text);
            if (spriteRender != nullptr) spriteRender->setPosition(this->x,this->y);
        }
        float x = 0;
        float y = 0;

        float x_width = 0;
        float y_height = 0;

        float x_width_text = 0;
        float y_height_text = 0;
        UIRect *rect = nullptr;
        sf::Text *text = new sf::Text();
        BaseUIObject(float x, float y, Scene *context) : x(x), y(y), context(context) {}
        BaseUIObject(float x, float y, BaseUIObject *anchor, Scene *context) :
        x(x),
        y(y),
        anchor(anchor),
        context(context)
        {
            x_width = x;
            y_height = y;

            if (this->anchor != nullptr){
                this->x = anchor->x + x;
                this->y = anchor->y + y;
            }
        }
        virtual void DrawHimself()
        {
            if (context != nullptr)
                if (context->windowContext != nullptr) {
                    if (spriteRender != nullptr) context->windowContext->draw(*spriteRender);
                    if (text != nullptr) context->windowContext->draw(*text);
                }
        }
        virtual void SetText(const std::string& st, sf::Font *font,  int size = 12, sf::Color *col = new sf::Color(1,1,1), float x = 0, float y = 0, sf::Uint32 style = sf::Text::Bold)
        {
            x_width_text = x;
            y_height_text = y;
            text->setFont(*font);
            text->setString(st);
            text->setCharacterSize(size);
            text->setFillColor(*col);
            text->setStyle(style);
            text->setPosition(this->x + x_width_text,this->y + y_height_text);
        }
        virtual void SetSprite(sf::Sprite *sprite){
            spriteRender = sprite;
            spriteRender->setPosition(x,y);
        }

        virtual void SetByTexture(sf::Texture *tex, int width, int height){
            spriteRender->setTexture(*tex);
            spriteRender->setTextureRect(sf::IntRect(0, 0, width, height));
            spriteRender->setPosition(x,y);
        }
        BaseUIObject() = default;

        void SetPosition(int x, int y)
        {
            x_width  = x;
            y_height = y;

            if (this->anchor != nullptr)
            {
                this->x = anchor->x + x_width;
                this->y = anchor->y + y_height;
            } else
            {
                this->x = x;
                this->y = y;
            }
            SetDrawObject();
        }
    };


    class Button : public BaseUIObject, IUICollision {
    public:
        bool activation = true;
        std::function<void()> onClick = []{};
       bool CheckCollision(float x, float y) override  {
           return rect->CollidePoint(x,y);
       }
        void SetText(const std::string& st, sf::Font *font,  int size = 12, sf::Color *col = new sf::Color(1,1,1), float x = 0, float y = 0, sf::Uint32 style = sf::Text::Bold) override
        {
            x_width_text = x;
            y_height_text = y;
            text->setFont(*font);
            text->setString(st);
            text->setCharacterSize(size);
            text->setFillColor(*col);
            text->setStyle(style);
            text->setPosition(this->x + x,this->y + y);
        }
        Button(float x, float y, BaseUIObject *anchor, Scene *context, UIRect *rect) : BaseUIObject(x,y,anchor,context) {
           this->rect = rect;

       }
        Button(float x, float y, Scene *context,  UIRect *rect) : BaseUIObject(x,y,context) {
           this->rect = rect;
       }


       void SetRect(){
           if (this->anchor != nullptr)
           {
               this->x = anchor->x + x_width;
               this->y = anchor->y + y_height;
           }
            this->rect->x_pos = x;
            this->rect->y_pos = y;
           SetDrawObject();
       }
    };


    class TextInfos
            {
    public:
        TextInfos(sf::Font*font, int size, sf::Color *col, float x, float y, sf::Uint32 style)

                :  font(font), size(size), col(col), x(x), y(y), style(style) {
        }
        void Add(std::vector<int> *n) {
            includes = n;
        };
        sf::Font *font;
        int size = 12;
        sf::Color *col = new sf::Color(1,1,1);
        float x = 0;
        float y = 0;
        sf::Uint32 style = sf::Text::Bold;
        std::vector<int> *includes  = new std::vector<int>();
    };




    class Info {
    public:
        explicit Info(std::vector<BaseUIObject *> *texts) : texts(texts) {}

    public:
        std::vector<BaseUIObject*> *texts = new std::vector<BaseUIObject*>();;
    };

}

#endif //AMERICANDEMOCRACYSIMULATOR_UI_H
