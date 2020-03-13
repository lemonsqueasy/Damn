//
// Created by Mon Le on 2020/3/12.
//

#ifndef DAMN_LEMONWORLD_H
#define DAMN_LEMONWORLD_H

#include "irrlicht.h"
#include "EventReceiver.h"
#include "irrBullet.h"
#include "LemonRigidObject.h"
#include <vector>

namespace lemon
{
    class LemonWorld
    {
    public:
        LemonWorld();
        ~LemonWorld();
        void show();
        void simulate();
        void action();
        bool setGravity(irr::core::vector3df gravity);
        bool addLemonRigidObject(LemonRigidObject* lemonRigidObject);


    private:
        static constexpr float FAR_VALUE_OF_CAMERA = 300000.f;//摄像机观察距离
        static constexpr float INIT_POSITION_OF_CAMERA_X = 40.f;
        static constexpr float INIT_POSITION_OF_CAMERA_Y = 40.f;
        static constexpr float INIT_POSITION_OF_CAMERA_Z = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_X = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_Y = 0;
        static constexpr float INIT_TARGET_OF_CAMERA_Z = 0;
        static constexpr float HALF_SIZE_OF_LIGHTS = 1500.f;
        static constexpr float RADIUS_OF_LIGHTS = 18.f;
        static constexpr float GRAVITY_OF_PHYSICSWORLD_X = 0;
        static constexpr float GRAVITY_OF_PHYSICSWORLD_Y = -9.8f;
        static constexpr float GRAVITY_OF_PHYSICSWORLD_Z = 0;

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

        std::vector<LemonRigidObject*> vectorForLemonRigidObjects;
        std::vector<LemonRigidObject*>::iterator iteratorForLemonRigidObjects;


        bool initGraphicWorld();
        bool destroyGraphicWorld();
        bool addCamera();
        bool createSkyBox();
        bool addLights();
        void graphicLoop();
        bool initPhysicsWorld();
        bool destroyPhysicsWorld();
        void physicsLoop();
        void actionLoop();




    };

}



#endif //DAMN_LEMONWORLD_H
