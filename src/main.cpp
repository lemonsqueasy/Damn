//
// Created by Mon Le on 2020/3/3.
//
#include <unistd.h>
#include "LemonWorld/LemonWorld.h"

int main()
{
    lemon::LemonWorld* lemonWorld = new lemon::LemonWorld();

    while(true)
    {

        if(!lemonWorld->run())
            break;


        usleep(100);
    }

    delete lemonWorld;
    lemonWorld = nullptr;

    return 0;
}

