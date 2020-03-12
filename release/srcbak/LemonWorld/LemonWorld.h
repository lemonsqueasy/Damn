//
// Created by Mon Le on 2020/3/4.
//

#ifndef DAMN_LEMONWORLD_H
#define DAMN_LEMONWORLD_H
#include "../GraphicWorld/GraphicWorld.h"
#include "../PhysicalWorld/PhysicalWorld.h"
#include "LemonObject.h"
#include <vector>

namespace lemon
{
    class LemonWorld
    {
    public:
        LemonWorld();
        ~LemonWorld();
        bool addLemonObject(LemonObject* lemonObject);
        bool showLemonWorld();
        bool updateLemonWorld();
        bool controlLemonWorld();
        bool setFPlayer(const char * name);


    private:
        std::vector<LemonObject*> vectorForLemonObjects;
        std::vector<LemonObject*>::iterator iteratorForLemonObjects;
        GraphicWorld* graphicWorld;
        PhysicalWorld* physicalWorld;
        EventReceiver* eventReceiver;
        LemonObject* fPlayer;


    };
}


#endif //DAMN_LEMONWORLD_H
