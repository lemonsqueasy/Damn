//
// Created by Mon Le on 2020/3/12.
//

#include "LemonWorld.h"
#include "../ToolsAndStructs/tools.h"
#include <unistd.h>

namespace lemon
{
    LemonWorld::LemonWorld()
    {
        initGraphicWorld();
        addCamera();
        createSkyBox();
        addLights();
        initPhysicsWorld();
        setGravity(irr::core::vector3df(GRAVITY_OF_PHYSICSWORLD_X, GRAVITY_OF_PHYSICSWORLD_Y, GRAVITY_OF_PHYSICSWORLD_Z));

    }


    LemonWorld::~LemonWorld()
    {
        destroyPhysicsWorld();
        destroyGraphicWorld();
    }


    bool LemonWorld::initGraphicWorld()
    {
        this->eventReceiver = new EventReceiver();
        this->irrlichtDevice = irr::createDevice(
                irr::video::EDT_OPENGL,
                irr::core::dimension2d<irr::u32>(640, 480),
                16,
                true,
                false,
                false,
                static_cast<irr::IEventReceiver*>(this->eventReceiver)
        );
        this->iVideoDriver = this->irrlichtDevice->getVideoDriver();
        this->iSceneManager = this->irrlichtDevice->getSceneManager();
        if(this->eventReceiver && this->irrlichtDevice && this->iVideoDriver && this->iSceneManager)
            return true;
        return false;
    }


    bool LemonWorld::destroyGraphicWorld()
    {
        //析构鬼火设备
        this->irrlichtDevice->drop();
        this->irrlichtDevice = nullptr;
        //析构事件接收器
        delete this->eventReceiver;
        this->eventReceiver = nullptr;
        //析构视频驱动抽象
        this->iVideoDriver->drop();
        this->iVideoDriver = nullptr;
        //析构场景管理器
        this->iSceneManager->drop();
        this->iSceneManager = nullptr;
        return true;
    }


    bool LemonWorld::addCamera()
    {
        if(!this->iSceneManager)
            return false;
        this->iCameraSceneNode = this->iSceneManager->addCameraSceneNodeFPS(
            0,
            30,
            0.01,
            -1,
            nullptr,
            0,
            true,
            0,
            false
        );
        this->iCameraSceneNode->setPosition({30, 30, 0});
        this->iCameraSceneNode->setTarget({0, 30, 0});
        if(this->iCameraSceneNode)
            return true;
        return false;
    }


    bool LemonWorld::createSkyBox()
    {
        if(!this->iSceneManager)
            return false;
        if(this->iSceneManager->addSkyBoxSceneNode(
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_tb.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_tb.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png")),
                this->iVideoDriver->getTexture(lemon::tools::getExePath("../media/skybox/skybox_wall.png"))
        ))
            return true;
        return false;
    }


    bool LemonWorld::addLights()
    {

        this->iLightSceneNode1 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS),
                irr::video::SColorf(255, 255, 255, 0),
                RADIUS_OF_LIGHTS
        );
        this->iLightSceneNode2 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(-HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS),
                irr::video::SColorf(255, 255, 255, 0),
                RADIUS_OF_LIGHTS
        );
        this->iLightSceneNode3 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS,-HALF_SIZE_OF_LIGHTS),
                irr::video::SColorf(255, 255, 255, 0),
                RADIUS_OF_LIGHTS
        );
        this->iLightSceneNode4 = this->iSceneManager->addLightSceneNode(
                0,
                irr::core::vector3df(-HALF_SIZE_OF_LIGHTS,HALF_SIZE_OF_LIGHTS,-HALF_SIZE_OF_LIGHTS),
                irr::video::SColorf(255, 255, 255, 0),
                RADIUS_OF_LIGHTS
        );
        if(this->iLightSceneNode1 && this->iLightSceneNode2 && this->iLightSceneNode3 && this->iLightSceneNode4)
            return true;
        return false;
    }


    void LemonWorld::graphicLoop()
    {

        while(this->irrlichtDevice->run())
        {
            this->iVideoDriver->beginScene(true, true, irr::video::SColor(255,0,0,0));
            this->iSceneManager->drawAll();
            this->iVideoDriver->endScene();
            if(this->eventReceiver->IsKeyDown(irr::KEY_ESCAPE))
                break;
            usleep(100);
        }

    }


    void LemonWorld::show()
    {
        this->graphicLoop();
    }


    bool LemonWorld::initPhysicsWorld()
    {
        if(!this->irrlichtDevice)
            return false;
        this->physicsWorld = createIrrBulletWorld(this->irrlichtDevice, true, false);
        if(this->physicsWorld)
            return true;
        return false;
    }

    bool LemonWorld::setGravity(irr::core::vector3df gravity)
    {
        if(!this->physicsWorld)
            return false;
        this->physicsWorld->setGravity(gravity);
        return true;
    }


    bool LemonWorld::destroyPhysicsWorld()
    {

        return true;
    }


    void LemonWorld::physicsLoop()
    {
        while(true)
        {
            this->physicsWorld->stepSimulation(100*0.000002f, 120);
            if(this->eventReceiver->IsKeyDown(irr::KEY_ESCAPE))
                break;
            usleep(100);
        }
    }

    void LemonWorld::simulate()
    {
        this->physicsLoop();
    }

    bool LemonWorld::addLemonRigidObject(LemonRigidObject *lemonRigidObject)
    {
        irr::scene::IMesh* iMesh = this->iSceneManager->getMesh(lemonRigidObject->getMeshPath());

        irr::scene::IMeshSceneNode* iMeshSceneNode = this->iSceneManager->addMeshSceneNode(
                iMesh,
                0,
                -1,
                lemonRigidObject->getInitPosition(),
                lemonRigidObject->getInitRotition(),
                lemonRigidObject->getInitScale()
                );
        if(lemonRigidObject->isSelfLight())
        {
            iMeshSceneNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }

        IGImpactMeshShape* igImpactMeshShape = new IGImpactMeshShape(iMeshSceneNode, iMesh, lemonRigidObject->getMass());
        IRigidBody* iRigidBody = this->physicsWorld->addRigidBody(igImpactMeshShape);
        iRigidBody->setActivationState(EActivationState::EAS_DISABLE_DEACTIVATION);
        lemonRigidObject->completeOb(
                iMesh,
                iMeshSceneNode,
                igImpactMeshShape,
                iRigidBody
                );
        this->vectorForLemonRigidObjects.push_back(lemonRigidObject);
        return true;
    }

    void LemonWorld::actionLoop()
    {
        while(true)
        {
            this->iteratorForLemonRigidObjects = this->vectorForLemonRigidObjects.begin();
            for(; this->iteratorForLemonRigidObjects != this->vectorForLemonRigidObjects.end(); ++this->iteratorForLemonRigidObjects)
            {
                (*this->iteratorForLemonRigidObjects)->onAction();
            }

            if(this->eventReceiver->IsKeyDown(irr::KEY_ESCAPE))
                break;
            usleep(1000);
        }
    }

    void LemonWorld::action()
    {
        this->actionLoop();
    }

}