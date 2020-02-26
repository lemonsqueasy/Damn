//
// Created by Mon Le on 2020/2/17.
//

#ifndef LEMONGAME_TOOL_FUNCTIONS_H
#define LEMONGAME_TOOL_FUNCTIONS_H
#include <iostream>
#include <mach-o/dyld.h>

namespace lemon
{
    namespace lemon_functions
    {

        /*
         * 在osx下获取程序执行目录
         */
        const char * getExePath(const char * fileName);



    }
}


#endif //LEMONGAME_TOOL_FUNCTIONS_H
