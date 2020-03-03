//
// Created by Mon Le on 2020/3/3.
//

#include "GUIDisplayer.h"

namespace lemon
{
    GUIDisplayer::GUIDisplayer(irr::IrrlichtDevice* irrlichtDevice)
    {
        if(!irrlichtDevice)
            exit(0);
        this->iguiEnvironment = irrlichtDevice->getGUIEnvironment();

        if(!this->iguiEnvironment)
            exit(0);
        this->textDisplayer = new TextDisplayer(this->iguiEnvironment);
    }

    TextDisplayer* GUIDisplayer::getTextDisplayer()
    {
        return this->textDisplayer;
    }

    void GUIDisplayer::drawAll()
    {
        if(this->iguiEnvironment)
        this->iguiEnvironment->drawAll();
    }
}