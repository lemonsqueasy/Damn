//
// Created by Mon Le on 2020/3/4.
//

#ifndef DAMN_LEMONOBJECT_H
#define DAMN_LEMONOBJECT_H

#include "../ToolsAndStructs/structs.h"
#include "../GraphicWorld/GraphicObject.h"
#include "../PhysicalWorld/PhysicalObject.h"
#include "IdCreator.h"

namespace lemon
{
    class LemonObject
    {
    public:
        LemonObject(
                const char* name,
                const char* meshPath,
                float mess,
                lemon::structs::LemonPoint3df halfSzie,
                lemon::structs::LemonPoint3df position,
                lemon::structs::LemonPoint3df rotation,
                lemon::structs::LemonPoint3df scale
                );
        LemonObject(
                const char* name,
                const char* meshPath,
                float mess,
                float halfSzie,
                lemon::structs::LemonPoint3df position,
                lemon::structs::LemonPoint3df rotation,
                lemon::structs::LemonPoint3df scale
        );
        ~LemonObject();
        int getId() const;
        const char* getName() const;
        GraphicObject* getGraphicObject() const;
        PhysicalObject* getPhysicalObject() const;





    private:
        int id;
        const char* name;
        GraphicObject* graphicObject;
        PhysicalObject* physicalObject;


    };
}



#endif //DAMN_LEMONOBJECT_H
