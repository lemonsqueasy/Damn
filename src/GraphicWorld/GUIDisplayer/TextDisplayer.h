//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_TEXTDISPLAYER_H
#define DAMN_TEXTDISPLAYER_H
#include "GuiFont/CGUITTFont.h"
#include "irrlicht/irrlicht.h"
#include "../../Tools/tools.h"

namespace lemon
{
    class TextDisplayer
    {
    public:
        TextDisplayer(irr::gui::IGUIEnvironment* iguiEnvironment);
        ~TextDisplayer();
        enum
        {
            INT,//区分类型
            FLOAT,//区分类型
            CONST_STR //区分类型
        };
        irr::gui::IGUIFont* getFont();
        bool combineStrForDisplay(int numOfParametersBehind,...);
        bool setPositionOfStr(irr::core::rect<irr::s32> position);
        bool setColorOfStr(irr::video::SColor color);
        bool drawText();
    private:
        static const int SIZE_OF_FONT = 25;
        const char * strForDisplay;
        irr::gui::IGUIFont* chineseFont;
        irr::core::rect<irr::s32> position;
        irr::video::SColor color;
    };
}



#endif //DAMN_TEXTDISPLAYER_H
