//
// Created by Mon Le on 2020/3/4.
//

#ifndef DAMN_LEMONWORLD_H
#define DAMN_LEMONWORLD_H
#include "../GraphicWorld/GraphicWorld.h"
#include "../PhysicsWorld/PhysicsWorld.h"
#include "LemonObject.h"

namespace lemon
{
    class LemonWorld
    {
    public:
        LemonWorld();
        ~LemonWorld();
        bool run();
        bool addLemonObject(LemonObject* lemonObject);

    private:
        GraphicWorld* graphicWorld;

    };
}


#endif //DAMN_LEMONWORLD_H
