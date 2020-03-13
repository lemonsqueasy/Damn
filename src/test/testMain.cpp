//#include <iostream>
//#include <pthread.h>
//#include <unistd.h>
//#include "irrlicht.h"
//#include "irrBullet.h"
//#include "../LemonWorld/EventReceiver.h"
//
//
//struct FuncArgs
//{
//    irrBulletWorld* physicsWorld;
//    float* deltaTime;
//};
//
//
//void* threadFunc(void* args)
//{
//    FuncArgs* as = (FuncArgs*)args;
//
//
//    while(true)
//    {
//        as->physicsWorld->stepSimulation((*(as->deltaTime))*0.0001f, 120);
//        usleep(1000);
//
//    }
//
//    return nullptr;
//}
//
//
//
//
//int main()
//{
//
//    lemon::EventReceiver* eventReceiver = new lemon::EventReceiver();
//    irr::IrrlichtDevice* device = irr::createDevice(
//            irr::video::EDT_OPENGL,
//            irr::core::dimension2d<irr::u32>(1920, 1080),
//            32,
//            true,
//            true,
//            true,
//            eventReceiver);
//
//    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
//    irr::video::IVideoDriver* driver = device->getVideoDriver();
//    irr::scene::ISceneManager* smgr = device->getSceneManager();
//    irrBulletWorld* physicsWorld = createIrrBulletWorld(device,  true, true);
//    physicsWorld->setGravity(irr::core::vector3df(0, -10, 0));
//
//
//
//    //map
//    irr::scene::IMesh* mapMesh = smgr->getMesh("/Users/monle/Documents/OSXProjects/CLionProjects/Damn/media/map/map.obj");
//    irr::scene::IMeshSceneNode* mapNode = smgr->addMeshSceneNode(mapMesh);
//    mapNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
//    mapNode->setPosition(irr::core::vector3df(0, 0, 0));
//    mapNode->setScale(irr::core::vector3df(3, 3, 3));
//    IGImpactMeshShape* phMapMeshShape = new IGImpactMeshShape(mapNode, mapMesh, 0);
//    IRigidBody* mapRigidBody = physicsWorld->addRigidBody(phMapMeshShape);
//
//
//
//    //character
//    irr::scene::IMesh* peopleMesh = smgr->getMesh("/Users/monle/Documents/OSXProjects/CLionProjects/Damn/media/ships/ship1.obj");
//    irr::scene::IMeshSceneNode* peopleNode = smgr->addMeshSceneNode(peopleMesh);
//    peopleNode->setScale(irr::core::vector3df(0.005, 0.005, 0.005));
//
//    irr::scene::IMeshSceneNode* peopleNodeNoVisi = smgr->addMeshSceneNode(peopleMesh);
//    peopleNodeNoVisi->setPosition({0,100,0});
//    peopleNodeNoVisi->setScale(irr::core::vector3df(0.005, 0.005, 0.005));
//    peopleNodeNoVisi->setVisible(false);
//    peopleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
//    peopleNode->setPosition(irr::core::vector3df(0, 0, 0));
//
//    //IGImpactMeshShape* phPeopleMeshShape = new IGImpactMeshShape(peopleNode, peopleMesh, 1);
//    //IBoxShape* phPeopleMeshShape = new IBoxShape(peopleNode, 1);
//    ISphereShape* phPeopleMeshShape = new ISphereShape(peopleNodeNoVisi,1);
//    IRigidBody* ppRigidBody = physicsWorld->addRigidBody(phPeopleMeshShape);
//    ppRigidBody->setActivationState(EActivationState::EAS_DISABLE_DEACTIVATION);
//    ppRigidBody->getWorldTransform().setTranslation({0,100,0});
//
//    //IKinematicCharacterController* iCharacter = new IKinematicCharacterController(physicsWorld);
//    //iCharacter->getWorldTransform().setTranslation(irr::core::vector3df(0, 100, 0));
//    //iCharacter->setGravity(-9.8);
//    //iCharacter->setJumpForce(20);
//
//
//
//    //camera
//    irr::scene::ICameraSceneNode* iCameraSceneNode = smgr->addCameraSceneNodeFPS(
//            0,
//            30,
//            0,
//            -1,
//            nullptr,
//            0,
//            true,
//            0,
//            false
//    );
//
//
//
//
//
//
//
//    float TimeStamp = device->getTimer()->getTime();
//    float* DeltaTime = new float;
//    *DeltaTime = 0;
//    FuncArgs* funcArgs = new FuncArgs;
//    funcArgs->physicsWorld = physicsWorld;
//    funcArgs->deltaTime = DeltaTime;
//    pthread_t* phThread = new pthread_t;
//    pthread_create(phThread, nullptr, threadFunc, funcArgs);
//
//
//
//
//    float moveSpeed = 0.3;
//    irr::core::vector3df moveDir = {0,0,0};
//    while(device->run())
//    {
//
//        driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
//        smgr->drawAll();
//        driver->endScene();
//
//        *DeltaTime = device->getTimer()->getTime() - TimeStamp;
//        TimeStamp = device->getTimer()->getTime();
//        iCameraSceneNode->setPosition(ppRigidBody->getWorldTransform().getTranslation()+irr::core::vector3df(0,3,0));
//        peopleNode->setPosition(ppRigidBody->getWorldTransform().getTranslation());
//        peopleNode->setRotation(irr::core::vector3df(0, iCameraSceneNode->getRotation().Y, 0));
//
//
//
//
//
//        if(eventReceiver->IsKeyDown(irr::KEY_KEY_W))
//        {
//            moveDir =  iCameraSceneNode->getTarget() - iCameraSceneNode->getPosition() ;
//            moveDir.normalize();
//            ppRigidBody->applyImpulse(moveDir*0.20, irr::core::vector3df(0, 0, 0));
//        }
//        else if(eventReceiver->IsKeyDown(irr::KEY_KEY_S))
//        {
//            moveDir = iCameraSceneNode->getTarget() - iCameraSceneNode->getPosition();
//            moveDir.normalize();
//
//        }
//        else if(eventReceiver->IsKeyDown(irr::KEY_KEY_A))
//        {
//            irr::core::CMatrix4<float> transform = mapRigidBody->getWorldTransform();
//            transform.setRotationDegrees({-2,0,0});
//            mapRigidBody->setWorldTransform(transform);
//            mapNode->setRotation({-2, 0, 0});
//
//        }
//        else if(eventReceiver->IsKeyDown(irr::KEY_KEY_D))
//        {
//
//            irr::core::CMatrix4<float> transform = mapRigidBody->getWorldTransform();
//            transform.setRotationDegrees({2,0,0});
//            mapRigidBody->setWorldTransform(transform);
//            mapNode->setRotation({2, 0, 0});
//
//
//
//        }
//        else
//        {
//            moveDir = {0,0,0};
//        }
//
//        if(eventReceiver->IsKeyDown(irr::KEY_SPACE))
//        {
//            ppRigidBody->applyImpulse(irr::core::vector3df(0,0.3,0), irr::core::vector3df(0, 1, 0));
//            //if(iCharacter->canJump())
//            //iCharacter->jump();
//        }
//
//
//        //iCharacter->setWalkDirection(-moveDir*moveSpeed);
//
//        usleep(100);
//
//
//    }
//
//    pthread_detach(*phThread);
//    device->drop();
//
//    return 0;
//}
//
//
