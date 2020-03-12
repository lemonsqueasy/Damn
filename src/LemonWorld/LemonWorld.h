//
// Created by Mon Le on 2020/3/12.
//

#ifndef DAMN_LEMONWORLD_H
#define DAMN_LEMONWORLD_H

#include "irrlicht.h"
#include "EventReceiver.h"
#include "irrBullet.h"

namespace lemon
{
    class LemonWorld
    {
    public:
        LemonWorld();
        ~LemonWorld();
        void show();
        void simulate();


    private:
        static constexpr float FAR_VALUE_OF_CAMERA = 300000;//摄像机观察距离
        static constexpr float INIT_POSITION_OF_CAMERA_X = 40;
        static constexpr float INIT_POSITION_OF_CAMERA_Y = 40;
        static constexpr float INIT_POSITION_OF_CAMERA_Z = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_X = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_Y = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_Z = 0;

        irr::IrrlichtDevice* irrlichtDevice;//鬼火设备
        irr::video::IVideoDriver* iVideoDriver;//图形驱动抽象
        irr::scene::ISceneManager* iSceneManager;//场景管理器
        lemon::EventReceiver* eventReceiver;//事件接收器
        irr::scene::ICameraSceneNode* iCameraSceneNode;//摄像机
        irr::scene::ILightSceneNode* iLightSceneNode1;//灯光
        irr::scene::ILightSceneNode* iLightSceneNode2;//灯光
        irr::scene::ILightSceneNode* iLightSceneNode3;//灯光
        irr::scene::ILightSceneNode* iLightSceneNode4;//灯光
        irrBulletWorld* physicsWorld;//世界的物理抽象




        bool initGraphicWorld();
        bool destroyGraphicWorld();
        bool addCamera();
        bool createSkyBox();
        bool addLights();
        void graphicLoop();
        bool initPhysicsWorld();
        bool destroyPhysicsWorld();
        void physicsLoop();




    };

}



#endif //DAMN_LEMONWORLD_H
