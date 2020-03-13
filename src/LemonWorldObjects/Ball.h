//
// Created by Mon Le on 2020/3/13.
//

#ifndef DAMN_BALL_H
#define DAMN_BALL_H

#include "../LemonWorld/LemonRigidObject.h"
#include "../ToolsAndStructs/tools.h"

namespace lemon
{
    class Ball : public LemonRigidObject
    {
    public:
        Ball(irr::core::vector3df initPosition, irr::core::vector3df initRotition, irr::core::vector3df initScale)
                :LemonRigidObject("map", lemon::tools::getExePath("../media/map/ball.obj"), 0.1, false, false,
                                  initPosition,
                                  initRotition,
                                  initScale
        )
        {

        }

        ~Ball();

        void onAction() override ;

    private:

    };
}

#endif //DAMN_BALL_H
