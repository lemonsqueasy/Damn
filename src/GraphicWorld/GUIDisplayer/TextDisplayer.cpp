//
// Created by Mon Le on 2020/3/3.
//

#include "TextDisplayer.h"

namespace lemon
{
    TextDisplayer::TextDisplayer(irr::gui::IGUIEnvironment* iguiEnvironment)
    {
        if(!iguiEnvironment)
            exit(0);
        this->chineseFont = irr::gui::CGUITTFont::createTTFont(
                iguiEnvironment,
                lemon::tools::getExePath("../media/font/msyh.ttf"),
                SIZE_OF_FONT
                );
        this->position = irr::core::rect<irr::s32>(0, 0, 0, 0);
        this->color = irr::video::SColor(255, 255, 255 ,255);
        iguiEnvironment->getSkin()->setFont(this->chineseFont);
    }

    bool TextDisplayer::combineStrForDisplay(int numOfParametersBehind,...)
    {
        unsigned maxLength = 1000;
        char *combinedStr = new char[maxLength];
        char * intStr = new char[100];
        char * floatStr = new char[100];

        va_list vlist;
        va_start(vlist,numOfParametersBehind);
        int currentType;
        for(int i = 0; i<numOfParametersBehind; i++)
        {
            if((i%2) == 0)
            {
                currentType = va_arg(vlist, int);

            }
            else
            {
                switch(currentType)
                {
                    case INT:
                        //int转字符串再拼接
                        sprintf(intStr, "%d", va_arg(vlist, int));
                        strcat(combinedStr, intStr);


                        break;
                    case FLOAT:
                        //float转字符串再拼接
                        sprintf(floatStr, "%8f", va_arg(vlist, double));
                        strcat(combinedStr, floatStr);

                        break;
                    case CONST_STR:
                        //直接拼接
                        strcat(combinedStr, va_arg(vlist, const char *));
                        break;

                    default:
                        std::cout<<"here"<<std::endl;
                        exit(0);

                }

            }

        }

        va_end(vlist);
        delete [] intStr;
        intStr = nullptr;
        delete [] floatStr;
        floatStr = nullptr;


        this->strForDisplay = combinedStr;
        if(this->strForDisplay)
            return true;
        return false;
    }

    bool TextDisplayer::setPositionOfStr(irr::core::rect<irr::s32> position)
    {
        this->position = position;
        return true;
    }

    bool TextDisplayer::setColorOfStr(irr::video::SColor color)
    {
        this->color = color;
        return true;
    }

    bool TextDisplayer::drawText()
    {
        if(this->strForDisplay)
        {
            this->chineseFont->draw(
                    this->strForDisplay,
                    this->position,
                    this->color
            );
            delete [] this->strForDisplay;
            this->strForDisplay = nullptr;
            return true;

        }
        return false;

    }

}