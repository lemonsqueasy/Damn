//
// Created by Mon Le on 2020/3/3.
//

#include "PhysicalWorld.h"

namespace lemon
{
    PhysicalWorld::PhysicalWorld()
    {
        if(!initWorld())
            exit(0);
    }

    PhysicalWorld::~PhysicalWorld()
    {

    }

    bool PhysicalWorld::initWorld()
    {
        this->defaultCollisionConfiguration = new btDefaultCollisionConfiguration();
        if(!this->defaultCollisionConfiguration)
            return false;

        this->collisionDispatcher = new btCollisionDispatcher(this->defaultCollisionConfiguration);
        if(!this->collisionDispatcher)
            return false;

        /*
        this->broadphaseInterface = new btDbvtBroadphase();
        if(!this->broadphaseInterface)
            return false;
        */

        this->sequentialImpulseConstraintSolver = new btSequentialImpulseConstraintSolver();
        if(!this->sequentialImpulseConstraintSolver)
            return false;


        btVector3 worldMin(-1000,-1000,-1000);
        btVector3 worldMax(1000,1000,1000);
        btAxisSweep3* sweepBP = new btAxisSweep3(worldMin,worldMax);
        this->broadphaseInterface = sweepBP;

        this->discreteDynamicsWorld = new btDiscreteDynamicsWorld(
                this->collisionDispatcher,
                this->broadphaseInterface,
                this->sequentialImpulseConstraintSolver,
                this->defaultCollisionConfiguration
                );
        if(!this->discreteDynamicsWorld)
            return false;

        this->discreteDynamicsWorld->setGravity(btVector3(DEFAULT_GRAVITY_X, DEFAULT_GRAVITY_Y, DEFAULT_GRAVITY_Z));
        return true;
    }

    bool PhysicalWorld::addPhysicalObject(PhysicalObject *physicalObject)
    {
        if((!this->discreteDynamicsWorld) || (!physicalObject))
            return false;
        this->discreteDynamicsWorld->addRigidBody(physicalObject->getRigidBody());
        return true;
    }

    bool PhysicalWorld::simulateWorld()
    {

        this->discreteDynamicsWorld->stepSimulation(1.f/60.f,10);

        return true;
    }
}