//
// Created by Mon Le on 2020/3/13.
//

#ifndef DAMN_BRICK_H
#define DAMN_BRICK_H

#include "../LemonWorld/LemonRigidObject.h"
#include "../ToolsAndStructs/tools.h"

namespace lemon
{
    class Brick : public LemonRigidObject
    {
    public:
        Brick(irr::core::vector3df initPosition, irr::core::vector3df initRotition, irr::core::vector3df initScale)
        :LemonRigidObject("map", lemon::tools::getExePath("../media/map/brick.obj"), 0.1, false, true,
                          initPosition,
                          initRotition,
                          initScale
        )
        {

        }

        ~Brick();

        void onAction() override ;

    private:

    };
}

#endif //DAMN_BRICK_H
