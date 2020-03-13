//
// Created by Mon Le on 2020/3/13.
//

#include "Board.h"

namespace lemon
{
    void Board::onAction()
    {
        this->setRotation(irr::core::vector3df(i, 0, 0));
        if(flagInc)
        {
            i = i + 0.01;
            if(i >= 10)
                flagInc = false;
        }
        else
        {
            i = i - 0.01;
            if(i <= -10)
                flagInc = true;
        }
    }
}