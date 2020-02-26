//
// Created by Mon Le on 2020/2/17.
//

#ifndef LEMONGAME_GLOBALS_H
#define LEMONGAME_GLOBALS_H
#include <irrlicht/irrlicht.h>
#include "../LEventReceiver/LEventReceiver.h"

namespace lemon
{
    class Globals
    {
    public:
        //用于初始化定义的全局变量
        Globals();
        //事件接收器
        static lemon::LEventReceiver* lReceiver;
        //鬼火设备
        static irr::IrrlichtDevice* irrlichtDevice;
        //绘图驱动抽象
        static irr::video::IVideoDriver* videoDriver;
        //场景管理器
        static irr::scene::ISceneManager* iSceneManager;
    };



}


#endif //LEMONGAME_GLOBALS_H
