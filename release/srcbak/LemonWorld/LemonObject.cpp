//
// Created by Mon Le on 2020/3/4.
//

#include "LemonObject.h"

namespace lemon
{
    LemonObject::LemonObject(
            const char* name,
            const char* meshPath,
            float mess,
            lemon::structs::LemonPoint3df halfSize,
            lemon::structs::LemonPoint3df position,
            lemon::structs::LemonPoint3df rotation,
            lemon::structs::LemonPoint3df scale
            )
    {
        this->name = name;
        this->id = IdCreator().getAnId();
        this->graphicObject = new GraphicObject(
                meshPath,
                irr::core::vector3df(position.x, position.y, position.z),
                irr::core::vector3df(rotation.x, rotation.y, rotation.z),
                irr::core::vector3df(scale.x, scale.y, scale.z)
                );
        this->physicalObject = new PhysicalObject(
                mess,
                btVector3(halfSize.x, halfSize.y, halfSize.z),
                btVector3(position.x, position.y, position.z),
                btQuaternion((btScalar)((rotation.y*M_PI)/180.0), (btScalar)((rotation.x*M_PI)/180.0), (btScalar)((rotation.z*M_PI)/180.0))
                );

    }

    LemonObject::LemonObject(
            const char* name,
            const char* meshPath,
            float mess,
            float halfSize,
            lemon::structs::LemonPoint3df position,
            lemon::structs::LemonPoint3df rotation,
            lemon::structs::LemonPoint3df scale
    )
    {
        this->name = name;
        this->id = IdCreator().getAnId();
        this->graphicObject = new GraphicObject(
                meshPath,
                irr::core::vector3df(position.x, position.y, position.z),
                irr::core::vector3df(rotation.x, rotation.y, rotation.z),
                irr::core::vector3df(scale.x, scale.y, scale.z)
        );
        this->physicalObject = new PhysicalObject(
                mess,
                (btScalar)halfSize,
                btVector3(position.x, position.y, position.z),
                btQuaternion((btScalar)((rotation.y*M_PI)/180.0), (btScalar)((rotation.x*M_PI)/180.0), (btScalar)((rotation.z*M_PI)/180.0))
        );

    }

    LemonObject::~LemonObject()
    {

    }

    GraphicObject* LemonObject::getGraphicObject() const
    {
        return this->graphicObject;
    }

    PhysicalObject* LemonObject::getPhysicalObject() const
    {
        return this->physicalObject;
    }

    int LemonObject::getId() const
    {
        return this->id;
    }

    const char* LemonObject::getName() const
    {
        return this->name;
    }

}