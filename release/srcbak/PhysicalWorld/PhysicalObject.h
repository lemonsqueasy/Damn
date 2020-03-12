//
// Created by Mon Le on 2020/3/6.
//

#ifndef DAMN_PHYSICALOBJECT_H
#define DAMN_PHYSICALOBJECT_H
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

namespace lemon
{
    class PhysicalObject
    {
    public:
        PhysicalObject(
                btScalar mass,
                btVector3 halfSize,
                btVector3 position,
                btQuaternion quaternion
                );
        PhysicalObject(
                btScalar mass,
                btScalar halfSize,
                btVector3 position,
                btQuaternion quaternion
        );
        ~PhysicalObject();
        btRigidBody* getRigidBody() const;


    private:
        btScalar mass;
        btCollisionShape* collisionShape;
        btDefaultMotionState* defaultMotionState;
        btRigidBody::btRigidBodyConstructionInfo* rigidBodyConstructionInfo;
        btRigidBody* rigidBody;

    };
}


#endif //DAMN_PHYSICALOBJECT_H
