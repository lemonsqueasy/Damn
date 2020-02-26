//
// Created by Mon Le on 2020/2/17.
//

#include <iostream>
#include "Globals.h"
namespace lemon
{
    lemon::LEventReceiver* Globals::lReceiver = nullptr;
    irr::IrrlichtDevice* Globals::irrlichtDevice = nullptr;
    irr::video::IVideoDriver* Globals::videoDriver = nullptr;
    irr::scene::ISceneManager* Globals::iSceneManager = nullptr;

    Globals::Globals()
    {
        //创建事件接收器
        lReceiver = new LEventReceiver();
        if(!lReceiver)
        {
            exit(0);
        }
        //创建鬼火设备
        irrlichtDevice = createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 24,
                                      true, false, false, lemon::Globals::lReceiver);
        if (!irrlichtDevice)
        {
            exit(0);
        }
        //创建绘图驱动
        videoDriver = irrlichtDevice->getVideoDriver();
        if(!videoDriver)
        {
            exit(0);
        }
        //创建设备管理器
        iSceneManager = irrlichtDevice->getSceneManager();
        if(!iSceneManager)
        {
            exit(0);
        }




    }

}