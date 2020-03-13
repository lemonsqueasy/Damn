//
// Created by Mon Le on 2020/3/13.
//

#ifndef DAMN_BOARD_H
#define DAMN_BOARD_H
#include "../LemonWorld/LemonRigidObject.h"
#include "../ToolsAndStructs/tools.h"

namespace lemon
{
    class Board : public LemonRigidObject
    {
    public:
        Board(irr::core::vector3df initPosition, irr::core::vector3df initRotition, irr::core::vector3df initScale)
        :LemonRigidObject("map", lemon::tools::getExePath("../media/map/floor.obj"), 0, false, false,
                          initPosition,
                          initRotition,
                          initScale
        )
        {
            this->i = 0;
            this->flagInc = true;
        }

        ~Board();

        void onAction() override ;

    private:
        float i;
        bool flagInc;
    };
}



#endif //DAMN_BOARD_H
