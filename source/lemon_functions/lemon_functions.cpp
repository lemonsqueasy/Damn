//
// Created by Mon Le on 2020/2/17.
//

#include "lemon_functions.h"

namespace lemon
{
    namespace lemon_functions
    {
        /*
        * 在osx下获取程序执行目录
        */
        const char * getExePath(const char *fileName)
        {
            unsigned maxLength = 1000;
            char *mediaPath = new char[maxLength];
            _NSGetExecutablePath(mediaPath, &maxLength);

            unsigned length = strlen(mediaPath) + strlen(fileName) + 1;
            if (length > maxLength)
                return nullptr;

            int binaryPathLength = strlen(mediaPath);
            int binaryNameLength = 0;

            for (int i = binaryPathLength - 1; i > 0; --i) {
                if (mediaPath[i] != '/')
                    ++binaryNameLength;
                else
                    break;
            }
            char endOfStr = static_cast<char>(0);
            memcpy(mediaPath + strlen(mediaPath) - binaryNameLength, &endOfStr, 1);
            strcat(mediaPath, fileName);
            return mediaPath;
        }

    }
}