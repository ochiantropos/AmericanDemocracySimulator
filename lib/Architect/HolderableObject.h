//
// Created by OchiAnthropos on 22.12.2023.
//

#ifndef AMERICANDEMOCRACYSIMULATOR_HOLDERABLEOBJECT_H
#define AMERICANDEMOCRACYSIMULATOR_HOLDERABLEOBJECT_H
#include "../Holders/DrawableHolder.h"

namespace Game
{
    class HolderableObject{
    public:
        DrawableHolder holder = DrawableHolder();
    };
}

#endif //AMERICANDEMOCRACYSIMULATOR_HOLDERABLEOBJECT_H
