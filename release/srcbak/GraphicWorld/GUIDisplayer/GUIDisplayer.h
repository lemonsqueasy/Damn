//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_GUIDISPLAYER_H
#define DAMN_GUIDISPLAYER_H
#include "irrlicht.h"
#include "TextDisplayer.h"

namespace lemon
{
    class GUIDisplayer
    {
    public:
        GUIDisplayer(irr::IrrlichtDevice* irrlichtDevice);
        ~GUIDisplayer();

        TextDisplayer* getTextDisplayer();
        void drawAll();

    private:
        irr::gui::IGUIEnvironment* iguiEnvironment;
        TextDisplayer* textDisplayer;
    };
}



#endif //DAMN_GUIDISPLAYER_H
