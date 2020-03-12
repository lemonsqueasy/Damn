//
// Created by Mon Le on 2020/3/6.
//

#ifndef DAMN_IDCREATOR_H
#define DAMN_IDCREATOR_H

namespace lemon
{

    class IdCreator
    {
    public:
        IdCreator();
        void reset();
        int getAnId() const;
    private:
        static int id;
    };
}



#endif //DAMN_IDCREATOR_H
