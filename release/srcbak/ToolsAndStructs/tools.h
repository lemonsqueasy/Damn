//
// Created by Mon Le on 2020/3/3.
//

#ifndef DAMN_TOOLS_H
#define DAMN_TOOLS_H


#include <iostream>
#include <mach-o/dyld.h>

namespace lemon
{
    namespace tools
    {
        enum {
            INT,//区分类型
            FLOAT,//区分类型
            CONST_STR //区分类型
        };

        /*
         * 在osx下获取程序执行目录
         */
        const char * getExePath(const char * fileName);

        /*
         * 参数拼接为字符串
         */
        const char * combineStrs(int numOfParametersBehind,...);



    }
}


#endif //DAMN_TOOLS_H
