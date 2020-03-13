//
// Created by Mon Le on 2020/3/12.
//

#include "WorldDriver.h"
#include "../LemonWorldObjects/Brick.h"
#include <pthread.h>
#include <unistd.h>


namespace lemon
{
    void WorldDriver::driveWorld(LemonWorld* lemonWorld)
    {
        pthread_t* physicsThread = new pthread_t;
        pthread_create(physicsThread, nullptr, reinterpret_cast<void *(*)(void *)>(thread1Func), (void*)lemonWorld);
        pthread_detach(*physicsThread);

        pthread_t* actionThread = new pthread_t;
        pthread_create(actionThread, nullptr, reinterpret_cast<void *(*)(void *)>(thread2Func), (void*)lemonWorld);
        pthread_detach(*actionThread);


    }

    void * WorldDriver::thread1Func(LemonWorld *lemonWorld)
    {
        lemonWorld->simulate();
        return nullptr;
    }

    void * WorldDriver::thread2Func(LemonWorld *lemonWorld)
    {
        lemonWorld->action();
        return nullptr;
    }


}