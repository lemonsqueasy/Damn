#include "LemonWorld/LemonWorld.h"
#include "LemonWorld/WorldDriver.h"

int main()
{
    lemon::LemonWorld* lemonWorld = new lemon::LemonWorld();
    lemon::WorldDriver::driveWorld(lemonWorld);

    lemonWorld->show();
    delete lemonWorld;
    lemonWorld = nullptr;
    return 0;
}