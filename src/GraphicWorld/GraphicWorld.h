//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_GRAPHICWORLD_H
#define DAMN_GRAPHICWORLD_H

#include "irrlicht/irrlicht.h"
#include "EventReceiver.h"
#include "GUIDisplayer/GUIDisplayer.h"

namespace lemon
{
    class GraphicWorld
    {
    public:
        GraphicWorld();
        ~GraphicWorld();
        bool drawWorld();
        void addSceneNode(irr::scene::ISceneNode* iSceneNode);

    private:
        static const int CAMERA_FAR_VALUE = 300000;
        constexpr static const float INIT_CAMERA_POSITION[3] = {100,100,100};
        constexpr static const float INIT_CAMERA_TARGET[3] = {0,0,0};

        irr::IrrlichtDevice* irrlichtDevice;//鬼火设备
        irr::video::IVideoDriver* iVideoDriver;//图形驱动抽象
        irr::scene::ISceneManager* iSceneManager;//场景管理器
        EventReceiver* eventReceiver;//事件接收器
        irr::scene::ICameraSceneNode* iCameraSceneNode;//摄像机
        GUIDisplayer* guiDisplayer;
        bool initWorld();




    };
}




#endif //DAMN_GRAPHICWORLD_H
