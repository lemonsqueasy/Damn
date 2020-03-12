//
// Created by Mon Le on 2020/3/12.
//

#ifndef DAMN_WORLDDRIVER_H
#define DAMN_WORLDDRIVER_H
#include "LemonWorld.h"

namespace lemon
{
    class WorldDriver
    {
    public:
        static void driveWorld(LemonWorld* lemonWorld);
        static void* thread1Func(LemonWorld* lemonWorld);
        static void* thread2Func(LemonWorld* lemonWorld);
    };
}


#endif //DAMN_WORLDDRIVER_H
