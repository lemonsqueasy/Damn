//
// Created by Mon Le on 2020/3/13.
//

#include "LemonRigidObject.h"


namespace lemon
{
    LemonRigidObject::LemonRigidObject(const char* name, const char* meshPath, float mass,bool flagOfFPlayer,bool selfLight,
            irr::core::vector3df initPosition,
            irr::core::vector3df initRotition,
            irr::core::vector3df initScale
    )
    {
        this->name = name;
        this->meshPath = meshPath;
        this->mass = mass;
        this->flagOfFPlayer = flagOfFPlayer;
        this->initPosition = initPosition;
        this->initRotition = initRotition;
        this->initScale = initScale;
        this->flagSelfLight = selfLight;
        this->iMesh = nullptr;
        this->iMeshSceneNode = nullptr;
        this->igImpactMeshShape = nullptr;
        this->iRigidBody = nullptr;
    }

    LemonRigidObject::~LemonRigidObject()
    {

    }

    void LemonRigidObject::onAction()
    {

    }

    const char* LemonRigidObject::getName() const
    {
        return this->name;
    }

    const char* LemonRigidObject::getMeshPath() const
    {
        return this->meshPath;
    }

    bool LemonRigidObject::isFPlayer() const
    {
        return this->flagOfFPlayer;
    }

    bool LemonRigidObject::setFPlayer(bool flagOfFPlayer)
    {
        this->flagOfFPlayer = flagOfFPlayer;
        return true;
    }

    irr::core::vector3df LemonRigidObject::getPosition() const
    {
        if(this->iRigidBody)
            return this->iRigidBody->getWorldTransform().getTranslation();
        return irr::core::vector3df(ERR_VALUE, ERR_VALUE, ERR_VALUE);
    }

    bool LemonRigidObject::setPosition(irr::core::vector3df position)
    {
        if(this->iRigidBody && this->iMeshSceneNode)
        {
            this->iRigidBody->setWorldTransform(
                    this->iRigidBody->getWorldTransform().setTranslation(position)
                    );
            this->iMeshSceneNode->setPosition(position);
            return true;
        }
        return false;
    }

    irr::core::vector3df LemonRigidObject::getRotation() const
    {
        if(this->iRigidBody)
            return this->iRigidBody->getWorldTransform().getRotationDegrees();
        return irr::core::vector3df(ERR_VALUE, ERR_VALUE, ERR_VALUE);
    }

    bool LemonRigidObject::setRotation(irr::core::vector3df rotation)
    {

        if(this->iRigidBody && this->iMeshSceneNode)
        {
            this->iRigidBody->setWorldTransform(
                    this->iRigidBody->getWorldTransform().setRotationDegrees(rotation)
                    );
            this->iMeshSceneNode->setRotation(rotation);
            return true;
        }

        return false;
    }

    irr::core::vector3df LemonRigidObject::getScale() const
    {
        if(this->iRigidBody)
            return this->iRigidBody->getWorldTransform().getScale();
        return irr::core::vector3df(ERR_VALUE, ERR_VALUE, ERR_VALUE);
    }

    bool LemonRigidObject::setScale(irr::core::vector3df scale)
    {
        if(this->iRigidBody && this->iMeshSceneNode)
        {
            this->iRigidBody->setWorldTransform(
                    this->iRigidBody->getWorldTransform().setScale(scale)
                    );
            this->iMeshSceneNode->setScale(scale);
            return true;
        }
        return false;
    }

    float LemonRigidObject::getMass() const
    {
        return this->mass;
    }

    void LemonRigidObject::completeOb(
            irr::scene::IMesh* iMesh,
            irr::scene::IMeshSceneNode* iMeshSceneNode,
            IGImpactMeshShape* igImpactMeshShape,
            IRigidBody* iRigidBody
    )
    {
        this->iMesh = iMesh;
        this->iMeshSceneNode = iMeshSceneNode;
        this->igImpactMeshShape = igImpactMeshShape;
        this->iRigidBody = iRigidBody;
    }

    irr::core::vector3df LemonRigidObject::getInitPosition() const
    {
        return this->initPosition;
    }

    irr::core::vector3df LemonRigidObject::getInitRotition() const
    {
        return this->initRotition;
    }

    irr::core::vector3df LemonRigidObject::getInitScale() const
    {
        return this->initScale;
    }

    bool LemonRigidObject::isSelfLight() const
    {
        return this->flagSelfLight;
    }

    bool LemonRigidObject::setFriction(float friction)
    {
        if(this->iRigidBody)
        {
            this->iRigidBody->setFriction(friction);
            return true;
        }
        return false;

    }
}