//
// Created by Mon Le on 2020/2/17.
//

#include <iostream>
#include "Globals.h"
namespace lemon
{
    LEventReceiver* Globals::lReceiver = nullptr;
    irr::IrrlichtDevice* Globals::device = nullptr;

    Globals::Globals(){
        lReceiver = new LEventReceiver();
        device = createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16,
                                               true, false, false, lemon::Globals::lReceiver);
        if (!device)
            exit(0);

    }

}