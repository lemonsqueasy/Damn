//
// Created by Mon Le on 2020/3/11.
//
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "irrlicht.h"
#include "irrBullet.h"
#include "GraphicWorld/EventReceiver.h"


struct FuncArgs
{
    irrBulletWorld* phsicsWorld;
    float* deltaTime;
};


void* threadFunc(void* args)
{
    FuncArgs* as = (FuncArgs*)args;


    while(true)
    {
        as->phsicsWorld->stepSimulation((*(as->deltaTime))*0.0001f, 120);
        usleep(1000);

    }

    return nullptr;
}




int main()
{

    lemon::EventReceiver* eventReceiver = new lemon::EventReceiver();
    irr::IrrlichtDevice* device = irr::createDevice(
            irr::video::EDT_OPENGL,
            irr::core::dimension2d<irr::u32>(640, 480),
            16,
            true,
            false,
            true,
            eventReceiver);

    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();

    irrBulletWorld* phsicsWorld = createIrrBulletWorld(device,  true, true);
    phsicsWorld->setGravity(irr::core::vector3df(0, -10, 0));


    irr::scene::IMesh* peopleMesh = smgr->getMesh("/Users/monle/Documents/OSXProjects/CLionProjects/Damn/media/persons/madara/Madara_Uchiha.obj");
    irr::scene::IMeshSceneNode* peopleNode = smgr->addMeshSceneNode(peopleMesh);
    peopleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    peopleNode->setPosition(irr::core::vector3df(0, 100, 0));
    //peopleNode->setScale(irr::core::vector3df(0.01, 0.01, 0.01));

    //IGImpactMeshShape* phPeopleMeshShape = new IGImpactMeshShape(peopleNode, peopleMesh, 1);
    //IRigidBody* ppRigidBody = phsicsWorld->addRigidBody(phPeopleMeshShape);
    //ppRigidBody->setActivationState(EActivationState::EAS_DISABLE_DEACTIVATION);

    IKinematicCharacterController* iCharacter = new IKinematicCharacterController(phsicsWorld);
    iCharacter->setGravity(-9.8);
    iCharacter->setJumpForce(30);



    irr::scene::IMesh* mapMesh = smgr->getMesh("/Users/monle/Documents/OSXProjects/CLionProjects/Damn/media/map/map.obj");
    irr::scene::IMeshSceneNode* mapNode = smgr->addMeshSceneNode(mapMesh);
    mapNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    mapNode->setPosition(irr::core::vector3df(0, 0, 0));
    mapNode->setScale(irr::core::vector3df(3, 3, 3));
    IGImpactMeshShape* phMapMeshShape = new IGImpactMeshShape(mapNode, mapMesh, 0);
    IRigidBody* mapRigidBody = phsicsWorld->addRigidBody(phMapMeshShape);






    irr::scene::ICameraSceneNode* iCameraSceneNode = smgr->addCameraSceneNodeFPS(
            0,
            100.0f,
            0.05f,
            -1,
            0,
            0,
            true,
            0.f,
            false,
            true
            );

    iCameraSceneNode->setPosition(irr::core::vector3df(0, 10, 10));
    iCameraSceneNode->setTarget(irr::core::vector3df(0, 0, 0));


    float TimeStamp = device->getTimer()->getTime();
    float* DeltaTime = new float;
    *DeltaTime = 0;


    FuncArgs* funcArgs = new FuncArgs;
    funcArgs->phsicsWorld = phsicsWorld;
    funcArgs->deltaTime = DeltaTime;

    pthread_t* phThread = new pthread_t;
    pthread_create(phThread, nullptr, threadFunc, funcArgs);

    while(device->run())
    {

        driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
        smgr->drawAll();
        driver->endScene();

        if(eventReceiver->IsKeyDown(irr::KEY_KEY_A))
        {

            //ppRigidBody->applyImpulse(irr::core::vector3df(-1,0,0),irr::core::vector3df(0,0,0));


            eventReceiver->clearKeyDown();
        }
        if(eventReceiver->IsKeyDown(irr::KEY_KEY_D))
        {

            //ppRigidBody->applyImpulse(irr::core::vector3df(1,0,0),irr::core::vector3df(0,0,0));

            eventReceiver->clearKeyDown();
        }
        if(eventReceiver->IsKeyDown(irr::KEY_KEY_W))
        {

            //ppRigidBody->applyImpulse(irr::core::vector3df(0.0,0,1),irr::core::vector3df(0,0,0));

            eventReceiver->clearKeyDown();
        }
        if(eventReceiver->IsKeyDown(irr::KEY_KEY_S))
        {

            //ppRigidBody->applyImpulse(irr::core::vector3df(0.0,0,-1),irr::core::vector3df(0,0,0));

            eventReceiver->clearKeyDown();
        }

        if(eventReceiver->IsKeyDown(irr::KEY_SPACE))
        {

            //ppRigidBody->applyImpulse(irr::core::vector3df(0,3,0),irr::core::vector3df(0,0,0));
            if(iCharacter->canJump())
                iCharacter->jump();
            eventReceiver->clearKeyDown();
        }

        *DeltaTime = device->getTimer()->getTime() - TimeStamp;
        TimeStamp = device->getTimer()->getTime();
        //phsicsWorld->stepSimulation((*DeltaTime)*0.001f, 120);
        iCameraSceneNode->setPosition(iCharacter->getWorldTransform().getTranslation());

        usleep(100);


    }

    pthread_detach(*phThread);
    device->drop();

    return 0;
}
