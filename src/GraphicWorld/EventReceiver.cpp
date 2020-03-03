//
// Created by Mon Le on 2020/3/3.
//

#include "EventReceiver.h"

namespace lemon
{
    EventReceiver::EventReceiver()
    {
        for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;

    }

    EventReceiver::~EventReceiver()
    {

    }

    //回调函数
    bool EventReceiver::OnEvent(const irr::SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        {
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        }


        return false;
    }


    //判断按键哪个按键被触发，比如传入A键，被触发则函数返回true
    bool EventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }
}
