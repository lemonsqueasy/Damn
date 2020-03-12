//
// Created by Mon Le on 2020/3/6.
//

#ifndef DAMN_GRAPHICOBJECT_H
#define DAMN_GRAPHICOBJECT_H
#include "irrlicht.h"

namespace lemon
{
    class GraphicObject
    {
    public:
        GraphicObject(
                const char* meshPath,
                irr::core::vector3df position,
                irr::core::vector3df rotation,
                irr::core::vector3df scale
                );
        ~GraphicObject();

        const char* getMeshPath() const;
        irr::core::vector3df getPosition() const;
        irr::core::vector3df getRotation() const;
        irr::core::vector3df getScale() const;
        bool setIAnimatedMeshSceneNode(irr::scene::IAnimatedMeshSceneNode* iAnimatedMeshSceneNode);
        irr::scene::IAnimatedMeshSceneNode* getIAnimatedMeshSceneNode() const;

    private:
        const char* meshPath;
        irr::core::vector3df position;
        irr::core::vector3df rotation;
        irr::core::vector3df scale;
        irr::scene::IAnimatedMeshSceneNode* iAnimatedMeshSceneNode;

    };
}



#endif //DAMN_GRAPHICOBJECT_H
