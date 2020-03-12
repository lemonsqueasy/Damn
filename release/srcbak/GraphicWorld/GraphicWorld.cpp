//
// Created by Mon Le on 2020/3/3.
//

#include "GraphicWorld.h"
#include "../ToolsAndStructs/tools.h"
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
                32,
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

        //this->iCameraSceneNode = this->iSceneManager->addCameraSceneNode();
        this->iCameraSceneNode = this->iSceneManager->addCameraSceneNodeFPS(
                0,
                30,
                0.02
                );
        if(!this->iCameraSceneNode)
            return false;
        this->iLightSceneNode1 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(1500,1500,1500),
                irr::video::SColorf(255, 255, 255, 0),
                15.0f
                );
        this->iLightSceneNode2 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(-1500,1500,1500),
                irr::video::SColorf(255, 255, 255, 0),
                15.0f
        );
        this->iLightSceneNode3 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(1500,1500,-1500),
                irr::video::SColorf(255, 255, 255, 0),
                15.0f
        );
        this->iLightSceneNode4 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(-1500,1500,-1500),
                irr::video::SColorf(255, 255, 255, 0),
                15.0f
        );
        this->iCameraSceneNode->setPosition(irr::core::vector3df(INIT_POSITION_OF_CAMERA_X, INIT_POSITION_OF_CAMERA_Y, INIT_POSITION_OF_CAMERA_Z));
        this->iCameraSceneNode->setTarget(irr::core::vector3df(INIT_TARGET_OF_CAMERA_X, INIT_TARGET_OF_CAMERA_Y, INIT_TARGET_OF_CAMERA_Z));
        this->iCameraSceneNode->setFarValue(FAR_VALUE_OF_CAMERA);

        this->guiDisplayer = new GUIDisplayer(this->irrlichtDevice);




        return true;
    }


    bool GraphicWorld::drawWorld()//主线程循环
    {

        if((!this->iVideoDriver) && (!this->iSceneManager))
            return false;

        this->irrlichtDevice->run();
        this->iVideoDriver->beginScene(true, true, irr::video::SColor(255,0,0,0));
        this->iSceneManager->drawAll();//先后顺序有关，会有遮挡







        this->iVideoDriver->endScene();



        if(this->eventReceiver->IsKeyDown(irr::KEY_ESCAPE))
            return false;

        return true;

    }

    irr::scene::IAnimatedMeshSceneNode* GraphicWorld::addSceneNode(
            const char* pathOfMesh,
            irr::core::vector3df initPosition,
            irr::core::vector3df initRotation,
            irr::core::vector3df initScale
    )
    {
        irr::scene::IAnimatedMeshSceneNode* iAnimatedMeshSceneNode = this->iSceneManager->addAnimatedMeshSceneNode(
                this->iSceneManager->getMesh(pathOfMesh)
                );
        iAnimatedMeshSceneNode->setPosition(initPosition);
        iAnimatedMeshSceneNode->setRotation(initRotation);
        iAnimatedMeshSceneNode->setScale(initScale);
        //iAnimatedMeshSceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);

        return iAnimatedMeshSceneNode;
    }

    bool GraphicWorld::addGraphicObject(GraphicObject *graphicObject)
    {
        irr::scene::IAnimatedMeshSceneNode* iAnimatedMeshSceneNode = addSceneNode(
                graphicObject->getMeshPath(),
                graphicObject->getPosition(),
                graphicObject->getRotation(),
                graphicObject->getScale()
                );
        //iAnimatedMeshSceneNode->setDebugDataVisible(true);
        graphicObject->setIAnimatedMeshSceneNode(iAnimatedMeshSceneNode);
        if(iAnimatedMeshSceneNode)
            return true;
        return false;
    }

    EventReceiver* GraphicWorld::getEventReceiver()
    {
        return this->eventReceiver;
    }


}