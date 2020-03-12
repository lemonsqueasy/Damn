//
// Created by Mon Le on 2020/3/6.
//

#ifndef DAMN_STRUCTS_H
#define DAMN_STRUCTS_H

namespace lemon
{
    namespace structs
    {
        class LemonPoint3df
        {
        public:
            LemonPoint3df(float x, float y, float z)
            :x(x),y(y),z(z)
            {

            }
            float x;
            float y;
            float z;
        };

    }
}


#endif //DAMN_STRUCTS_H
