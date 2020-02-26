//
// Created by Mon Le on 2020/2/17.
//

#include "LEventReceiver.h"
namespace lemon
{
    LEventReceiver::LEventReceiver()
    {
        for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }



// This is the one method that we have to implement
    bool LEventReceiver::OnEvent(const irr::SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

        return false;
    }


// This is used to check whether a key is being held down
    bool LEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
}
