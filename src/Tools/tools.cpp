//
// Created by Mon Le on 2020/3/3.
//

#include "tools.h"

namespace lemon
{
    namespace tools
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

            for (int i = binaryPathLength - 1; i > 0; --i)
            {
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

        /*
         * 参数拼接为字符串函数
         * 切记，该函数比较危险，穿参必须严格满足以下格式
         * 第一个参数表示其后参数个数，一定为偶数个
         * 参数对，前面表示类型，后面表示值,对值务必使用强制类型转换，以提高安全性
        */
        const char * combineStrs(int numOfParametersBehind,...)
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


            return combinedStr;

        }

    }
}