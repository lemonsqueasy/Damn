#include "LemonWorld/LemonWorld.h"
#include "LemonWorld/WorldDriver.h"
#include "LemonWorldObjects/Board.h"
#include "ToolsAndStructs/tools.h"
#include "LemonWorldObjects/Brick.h"
#include "LemonWorldObjects/Ball.h"


int main()
{
    lemon::LemonWorld* lemonWorld = new lemon::LemonWorld();
    lemon::Board* map = new lemon::Board({0, 0, 0}, {0, 0, 0}, {1, 1, 1});
    lemonWorld->addLemonRigidObject(map);
    //lemon::Brick* brick = new lemon::Brick({0, 100, 0}, {0, 0, 0}, {1, 1, 1});
    //lemonWorld->addLemonRigidObject(brick);
    lemon::Ball* ball = new lemon::Ball({0, 100, 0}, {0, 0, 0}, {1, 1, 1});
    lemonWorld->addLemonRigidObject(ball);

    lemon::WorldDriver::driveWorld(lemonWorld);
    lemonWorld->show();
    delete lemonWorld;
    lemonWorld = nullptr;
    return 0;
}