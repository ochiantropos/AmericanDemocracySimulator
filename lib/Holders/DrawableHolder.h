//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_DRAWABLEHOLDER_H
#define AMERICANDEMOCRACYSIMULATOR_DRAWABLEHOLDER_H
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
namespace Game {
    class DrawableHolder {
    public:
        std::map<std::string,sf::Sprite> objects;
        DrawableHolder();
        explicit DrawableHolder( const std::map<std::string,sf::Sprite>&  vectorData);
        void AddDrawable(  sf::Sprite object, const std::string& name);
        void AddDrawable(  sf::Sprite object);
        void DeleteDrawable( std::string &name);
        void DeleteDrawable(  const sf::Sprite& object, const std::string& name);
        void addObject( const std::string& key, sf::Sprite object);
        void removeObject(const std::string &key);
    };
} // Game
#endif //AMERICANDEMOCRACYSIMULATOR_DRAWABLEHOLDER_H
