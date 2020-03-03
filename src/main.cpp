//
// Created by Mon Le on 2020/3/3.
//
#include <unistd.h>
#include "GraphicWorld/GraphicWorld.h"

int main()
{
    lemon::GraphicWorld* graphicWorld = new lemon::GraphicWorld();

    while(true)
    {

        if(!graphicWorld->drawWorld())
            break;


        usleep(100);
    }

    delete graphicWorld;
    graphicWorld = nullptr;

    return 0;
}

