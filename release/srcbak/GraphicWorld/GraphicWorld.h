//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_GRAPHICWORLD_H
#define DAMN_GRAPHICWORLD_H

#include "irrlicht.h"
#include "EventReceiver.h"
#include "GUIDisplayer/GUIDisplayer.h"
#include "GraphicObject.h"

namespace lemon
{
    class GraphicWorld
    {
    public:
        GraphicWorld();
        ~GraphicWorld();
        bool addGraphicObject(GraphicObject* graphicObject);
        bool drawWorld();
        EventReceiver* getEventReceiver();


    private:
        static const int FAR_VALUE_OF_CAMERA = 300000;
        constexpr static const float INIT_POSITION_OF_CAMERA_X = 40;
        constexpr static const float INIT_POSITION_OF_CAMERA_Y = 40;
        constexpr static const float INIT_POSITION_OF_CAMERA_Z = 0;
        constexpr static const float INIT_TARGET_OF_CAMERA_X = 0;
        constexpr static const float INIT_TARGET_OF_CAMERA_Y = 0;
        constexpr static const float INIT_TARGET_OF_CAMERA_Z = 0;


        irr::IrrlichtDevice* irrlichtDevice;//鬼火设备
        irr::video::IVideoDriver* iVideoDriver;//图形驱动抽象
        irr::scene::ISceneManager* iSceneManager;//场景管理器
        EventReceiver* eventReceiver;//事件接收器
        irr::scene::ICameraSceneNode* iCameraSceneNode;//摄像机
        irr::scene::ILightSceneNode* iLightSceneNode1;
        irr::scene::ILightSceneNode* iLightSceneNode2;
        irr::scene::ILightSceneNode* iLightSceneNode3;
        irr::scene::ILightSceneNode* iLightSceneNode4;
        GUIDisplayer* guiDisplayer;
        bool initWorld();

        irr::scene::IAnimatedMeshSceneNode* addSceneNode(
                const char* pathOfMesh,
                irr::core::vector3df initPosition,
                irr::core::vector3df initRotation,
                irr::core::vector3df initScale
        );



    };
}




#endif //DAMN_GRAPHICWORLD_H
