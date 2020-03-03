//
// Created by Mon Le on 2020/3/3.
//

#include "GraphicWorld.h"
#include "../Tools/tools.h"
#include <thread>
namespace lemon
{
    GraphicWorld::GraphicWorld()
    {
        if(!initWorld())
            exit(0);


    }

    GraphicWorld::~GraphicWorld()
    {
        this->irrlichtDevice->drop();
        this->irrlichtDevice = nullptr;
        this->iSceneManager = nullptr;
        this->iVideoDriver = nullptr;
        this->iCameraSceneNode = nullptr;
        delete this->eventReceiver;
        this->eventReceiver = nullptr;
    }

    bool GraphicWorld::initWorld()
    {
        this->eventReceiver = new EventReceiver();
        if(!this->eventReceiver)
            return false;

        this->irrlichtDevice = irr::createDevice(
                irr::video::EDT_OPENGL,
                irr::core::dimension2d<irr::u32>(1920, 1080),
                24,
                true,
                false,
                false,
                static_cast<irr::IEventReceiver*>(this->eventReceiver)
        );
        if(!this->irrlichtDevice)
            return false;
        this->irrlichtDevice->getCursorControl()->setVisible(false);

        this->iVideoDriver = this->irrlichtDevice->getVideoDriver();
        if(!this->iVideoDriver)
            return false;
        this->iSceneManager = this->irrlichtDevice->getSceneManager();
        if(!this->iSceneManager)
            return false;
        this->iSceneManager->addSkyBoxSceneNode(
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_tb.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_tb.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png"))
                );

        this->iCameraSceneNode = this->iSceneManager->addCameraSceneNode();
        if(!this->iCameraSceneNode)
            return false;
        this->iCameraSceneNode->setPosition(irr::core::vector3df(INIT_CAMERA_POSITION[0], INIT_CAMERA_POSITION[1], INIT_CAMERA_POSITION[2]));
        this->iCameraSceneNode->setTarget(irr::core::vector3df(INIT_CAMERA_TARGET[0], INIT_CAMERA_TARGET[1], INIT_CAMERA_TARGET[2]));
        this->iCameraSceneNode->setFarValue(CAMERA_FAR_VALUE);

        this->guiDisplayer = new GUIDisplayer(this->irrlichtDevice);




        return true;
    }

    irr::f32 i = 0;
    bool GraphicWorld::drawWorld()//主线程循环
    {

        if((!this->iVideoDriver) && (!this->iSceneManager))
            return false;

        this->irrlichtDevice->run();

        this->iVideoDriver->beginScene(true, true, irr::video::SColor(255,0,0,0));
        this->iSceneManager->drawAll();//先后顺序有关，会有遮挡


        this->iCameraSceneNode->setTarget(irr::core::vector3df(0, (irr::f32)i, 0));





        this->iVideoDriver->endScene();


        if(this->eventReceiver->IsKeyDown(irr::KEY_UP))
            ++i;
        if(this->eventReceiver->IsKeyDown(irr::KEY_DOWN))
            --i;


        if(this->eventReceiver->IsKeyDown(irr::KEY_ESCAPE))
            return false;

        return true;

    }


    void GraphicWorld::addSceneNode(irr::scene::ISceneNode *iSceneNode)
    {

    }

}