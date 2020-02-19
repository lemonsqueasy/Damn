//
// Created by Mon Le on 2020/2/17.
//

#ifndef LEMONGAME_LEVENTRECEIVER_H
#define LEMONGAME_LEVENTRECEIVER_H
#include <irrlicht/irrlicht.h>

class LEventReceiver : public irr::IEventReceiver{
private:
    // We use this array to store the current state of each key
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
public:
    LEventReceiver();
    //必须重写的回调函数，用于接受设备传来的事件
    virtual bool OnEvent(const irr::SEvent& event) override;
    //检测是不是这个按键被触发
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;


};

#endif //LEMONGAME_LEVENTRECEIVER_H
