//
// Created by OchiAnthropos on 21.12.2023.
//

#include "GameObject.h"
#include "../Debugger/Debugger.h"
namespace Game
{
    void  GameObject:: update(float deltaTime)
    {
        Debugger::Log("Update object");
    }
    void GameObject::draw(sf::RenderWindow& window)
    {
        Debugger::Log("Draw object");

    }

    GameObject::GameObject(Scene *context) {
        currentContext = (Scene *) context;
    }

    GameObject::GameObject() = default;
} // Game