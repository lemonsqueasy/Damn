//
// Created by Mon Le on 2020/3/4.
//

#include "LemonWorld.h"
#include <cmath>
namespace lemon
{
    LemonWorld::LemonWorld()
    {
        this->graphicWorld = new GraphicWorld();
        this->physicalWorld = new PhysicalWorld();
        this->eventReceiver = this->graphicWorld->getEventReceiver();
    }

    LemonWorld::~LemonWorld()
    {
        delete this->graphicWorld;
        this->graphicWorld = nullptr;
    }


    bool LemonWorld::addLemonObject(LemonObject *lemonObject)
    {

        if(!this->graphicWorld->addGraphicObject(lemonObject->getGraphicObject()))
            return false;

        this->physicalWorld->addPhysicalObject(lemonObject->getPhysicalObject());

        this->vectorForLemonObjects.push_back(lemonObject);
        return true;
    }

    bool LemonWorld::showLemonWorld()
    {
        if(!this->graphicWorld->drawWorld())
            return false;


        return true;
    }

    bool LemonWorld::updateLemonWorld()
    {

        this->physicalWorld->simulateWorld();


        this->iteratorForLemonObjects = this->vectorForLemonObjects.begin();
        for(; this->iteratorForLemonObjects != this->vectorForLemonObjects.end(); ++this->iteratorForLemonObjects)
        {
            LemonObject* lemonObject = *this->iteratorForLemonObjects;

            btTransform transform = lemonObject->getPhysicalObject()->getRigidBody()->getWorldTransform();

            btVector3 currentPosition = transform.getOrigin();
            btQuaternion currentRotatian = transform.getRotation();

            irr::core::quaternion currentQuaternion(currentRotatian.getX(), currentRotatian.getY(), currentRotatian.getZ(), currentRotatian.getW());
            irr::core::vector3df euler;
            currentQuaternion.toEuler(euler);
            euler *= irr::core::RADTODEG;

            lemonObject->getGraphicObject()->getIAnimatedMeshSceneNode()->setPosition(
                    irr::core::vector3df(
                            currentPosition.getX(),
                            currentPosition.getY(),
                            currentPosition.getZ()
                            )
                    );
            lemonObject->getGraphicObject()->getIAnimatedMeshSceneNode()->setRotation(euler);
            //printf("%f, %f, %f\n",currentPosition.getX(),currentPosition.getY(),currentPosition.getZ());

        }

        controlLemonWorld();


        return true;
    }

    bool LemonWorld::setFPlayer(const char *name)
    {
        this->fPlayer = nullptr;
        this->iteratorForLemonObjects = this->vectorForLemonObjects.begin();
        for(; this->iteratorForLemonObjects != this->vectorForLemonObjects.end(); ++this->iteratorForLemonObjects)
        {
            if((strcmp((*this->iteratorForLemonObjects)->getName(), name) == 0))
                this->fPlayer = *this->iteratorForLemonObjects;
        }

        if(this->fPlayer)
            return true;

        return false;
    }

    bool LemonWorld::controlLemonWorld()
    {
        if(!this->eventReceiver)
            return false;

        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_Q))
        {

            printf("Q\n");

            this->fPlayer->getPhysicalObject()->getRigidBody()->applyCentralImpulse(btVector3(0,1,0));
        }
/*
        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_E))
        {
            printf("E\n");
            this->fPlayer->getPhysicalObject()->getRigidBody()->applyTorqueImpulse(btVector3(0,1,0));
        }

        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_W))
        {

        }

        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_A))
        {
            this->fPlayer->getPhysicalObject()->getRigidBody()->applyTorqueImpulse(btVector3(0,0,0));
        }

        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_S))
        {

            this->fPlayer->getPhysicalObject()->getRigidBody()->applyCentralImpulse(btVector3(0,0,0));

        }

        if(this->eventReceiver->IsKeyDown(irr::KEY_KEY_D))
        {
            this->fPlayer->getPhysicalObject()->getRigidBody()->applyTorqueImpulse(btVector3(0,0,0));
        }
*/


        this->eventReceiver->clearKeyDown();
        return true;
    }
}