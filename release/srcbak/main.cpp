////
//// Created by Mon Le on 2020/3/3.
////
//#include <unistd.h>
//#include "ToolsAndStructs/structs.h"
//#include "LemonWorld/LemonWorld.h"
//#include <thread>
//
//void updateWorld(lemon::LemonWorld* lemonWorld)
//{
//    while (true)
//    {
//        if(!lemonWorld)
//            break;
//        lemonWorld->updateLemonWorld();
//        usleep(10000);
//    }
//    return;
//
//}
//
//int main()
//{
//    lemon::LemonWorld* lemonWorld = new lemon::LemonWorld();
//
//    lemon::LemonObject* map = new lemon::LemonObject(
//            "floor",
//            lemon::tools::getExePath("../media/test/floor.obj"),
//            0,
//            lemon::structs::LemonPoint3df(10, 1, 10),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//            );
//
//    lemon::LemonObject* wall1 = new lemon::LemonObject(
//            "wall1",
//            lemon::tools::getExePath("../media/test/wall.obj"),
//            0,
//            lemon::structs::LemonPoint3df(10, 4, 1),
//            lemon::structs::LemonPoint3df(0, 0, -10),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* wall2 = new lemon::LemonObject(
//            "wall2",
//            lemon::tools::getExePath("../media/test/wall.obj"),
//            0,
//            lemon::structs::LemonPoint3df(10, 4, 1),
//            lemon::structs::LemonPoint3df(0, 0, 10),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* wall3 = new lemon::LemonObject(
//            "wall3",
//            lemon::tools::getExePath("../media/test/wall.obj"),
//            0,
//            lemon::structs::LemonPoint3df(10, 4, 1),
//            lemon::structs::LemonPoint3df(10, 0, 0),
//            lemon::structs::LemonPoint3df(0, 90, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* wall4 = new lemon::LemonObject(
//            "wall4",
//            lemon::tools::getExePath("../media/test/wall.obj"),
//            0,
//            lemon::structs::LemonPoint3df(10, 4, 1),
//            lemon::structs::LemonPoint3df(-10, 0, 0),
//            lemon::structs::LemonPoint3df(0, 90, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* manara = new lemon::LemonObject(
//            "manara",
//            lemon::tools::getExePath("../media/persons/madara/Madara_Uchiha.obj"),
//            1,
//            lemon::structs::LemonPoint3df(1, 1, 1),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(0, 90, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* ball1 = new lemon::LemonObject(
//            "ball1",
//            lemon::tools::getExePath("../media/test/hello.obj"),
//            10,
//            1,
//            lemon::structs::LemonPoint3df(0, 150, 0),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemon::LemonObject* ball2 = new lemon::LemonObject(
//            "ball2",
//            lemon::tools::getExePath("../media/test/hello.obj"),
//            100,
//            1,
//            lemon::structs::LemonPoint3df(0, 500, 0),
//            lemon::structs::LemonPoint3df(0, 0, 0),
//            lemon::structs::LemonPoint3df(1, 1, 1)
//    );
//
//    lemonWorld->addLemonObject(map);
//    lemonWorld->addLemonObject(wall1);
//    lemonWorld->addLemonObject(wall2);
//    lemonWorld->addLemonObject(wall3);
//    lemonWorld->addLemonObject(wall4);
//    lemonWorld->addLemonObject(manara);
//    //lemonWorld->addLemonObject(ball1);
//    //lemonWorld->addLemonObject(ball2);
//
//    lemonWorld->setFPlayer("manara");
//
//
//    std::thread updateThread(updateWorld,lemonWorld);//开启一个线程用于更新坐标
//
//
//    while(true)
//    {
//
//        if(!lemonWorld->showLemonWorld())//主线程绘制图形
//            break;
//        usleep(1000);
//    }
//
//
//    delete lemonWorld;
//    lemonWorld = nullptr;
//    //updateThread.join();
//    updateThread.detach();
//
//
//    return 0;
//}
//
//
