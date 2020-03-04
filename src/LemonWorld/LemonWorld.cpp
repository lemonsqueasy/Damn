//
// Created by Mon Le on 2020/3/4.
//

#include "LemonWorld.h"

namespace lemon
{
    LemonWorld::LemonWorld()
    {
        this->graphicWorld = new GraphicWorld();
    }

    LemonWorld::~LemonWorld()
    {
        delete this->graphicWorld;
        this->graphicWorld = nullptr;
    }

    bool LemonWorld::run()
    {
        if(!this->graphicWorld->drawWorld())
            return false;


        return true;
    }
}