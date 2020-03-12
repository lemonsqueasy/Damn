//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_PHYSICALWORLD_H
#define DAMN_PHYSICALWORLD_H
#include "PhysicalObject.h"

namespace lemon
{
    class PhysicalWorld
    {
    public:
        PhysicalWorld();
        ~PhysicalWorld();
        bool addPhysicalObject(PhysicalObject* physicalObject);
        bool simulateWorld();

    private:
        const float DEFAULT_GRAVITY_X = 0;
        const float DEFAULT_GRAVITY_Y = -0.8;
        const float DEFAULT_GRAVITY_Z = 0;
        btDefaultCollisionConfiguration* defaultCollisionConfiguration;
        btCollisionDispatcher* collisionDispatcher;
        btBroadphaseInterface* broadphaseInterface;
        btSequentialImpulseConstraintSolver* sequentialImpulseConstraintSolver;
        btDiscreteDynamicsWorld* discreteDynamicsWorld;

        bool initWorld();

    };
}


#endif //DAMN_PHYSICALWORLD_H
