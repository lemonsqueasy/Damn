//
// Created by Mon Le on 2020/3/6.
//

#include "PhysicalObject.h"

namespace lemon
{
    PhysicalObject::PhysicalObject(
            btScalar mass,
            btVector3 halfSize,
            btVector3 position,
            btQuaternion quaternion
            )
    {
        this->mass = mass;


        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(position);
        transform.setRotation(quaternion);
        this->defaultMotionState = new btDefaultMotionState(transform);
        if(!this->defaultMotionState)
            exit(0);

        this->collisionShape = new btBoxShape(halfSize);
        if(!this->collisionShape)
            exit(0);

        bool isDynamic = (mass != 0.f);
        btVector3 localInertia(0,0,0);
        if (isDynamic)
            this->collisionShape->calculateLocalInertia(mass,localInertia);


        this->rigidBodyConstructionInfo = new btRigidBody::btRigidBodyConstructionInfo(
                mass,
                this->defaultMotionState,
                this->collisionShape,
                localInertia
        );
        if(!this->rigidBodyConstructionInfo)
            exit(0);

        this->rigidBody = new btRigidBody(*rigidBodyConstructionInfo);


    }

    PhysicalObject::PhysicalObject(
            btScalar mass,
            btScalar halfSize,
            btVector3 position,
            btQuaternion quaternion
    )
    {
        this->mass = mass;


        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(position);
        transform.setRotation(quaternion);
        this->defaultMotionState = new btDefaultMotionState(transform);
        if(!this->defaultMotionState)
            exit(0);

        this->collisionShape = new btSphereShape(halfSize);
        if(!this->collisionShape)
            exit(0);

        bool isDynamic = (mass != 0.f);
        btVector3 localInertia(0,0,0);
        if (isDynamic)
            this->collisionShape->calculateLocalInertia(mass,localInertia);


        this->rigidBodyConstructionInfo = new btRigidBody::btRigidBodyConstructionInfo(
                mass,
                this->defaultMotionState,
                this->collisionShape,
                localInertia
        );
        if(!this->rigidBodyConstructionInfo)
            exit(0);

        this->rigidBody = new btRigidBody(*rigidBodyConstructionInfo);


    }

    PhysicalObject::~PhysicalObject()
    {

    }


    btRigidBody* PhysicalObject::getRigidBody() const
    {
        return rigidBody;
    }



}