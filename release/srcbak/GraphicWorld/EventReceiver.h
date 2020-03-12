//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_EVENTRECEIVER_H
#define DAMN_EVENTRECEIVER_H
#include "irrlicht.h"

namespace lemon
{
class EventReceiver : public irr::IEventReceiver
    {
    private:
        // 按键触发结果存储
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
    public:
        EventReceiver();
        ~EventReceiver();
        //必须重写的回调函数，用于接受设备传来的事件
        virtual bool OnEvent(const irr::SEvent& event) override;
        //检测是不是这个按键被触发
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

        void clearKeyDown();
    };
}



#endif //DAMN_EVENTRECEIVER_H
