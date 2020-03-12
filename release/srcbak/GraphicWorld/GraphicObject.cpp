//
// Created by Mon Le on 2020/3/6.
//

#include "GraphicObject.h"

namespace lemon
{
    GraphicObject::GraphicObject(
            const char* meshPath,
            irr::core::vector3df position,
            irr::core::vector3df rotation,
            irr::core::vector3df scale
            )
    {
        this->meshPath = meshPath;
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;
        this->iAnimatedMeshSceneNode = nullptr;

    }

    GraphicObject::~GraphicObject()
    {

    }

    const char* GraphicObject::getMeshPath() const
    {
        return this->meshPath;
    }

    irr::core::vector3df GraphicObject::getPosition() const
    {
        return this->position;
    }
    irr::core::vector3df GraphicObject::getRotation() const
    {
        return this->rotation;
    }

    irr::core::vector3df GraphicObject::getScale() const
    {
        return this->scale;
    }

    bool  GraphicObject::setIAnimatedMeshSceneNode(irr::scene::IAnimatedMeshSceneNode *iAnimatedMeshSceneNode)
    {
        this->iAnimatedMeshSceneNode = iAnimatedMeshSceneNode;
        if(this->iAnimatedMeshSceneNode)
            return true;
        return false;
    }

    irr::scene::IAnimatedMeshSceneNode* GraphicObject::getIAnimatedMeshSceneNode() const
    {
        return this->iAnimatedMeshSceneNode;
    }
}