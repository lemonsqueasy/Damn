//
// Created by Mon Le on 2020/3/6.
//

#include "IdCreator.h"

namespace lemon
{

    int IdCreator::id = 0;

    IdCreator::IdCreator()
    {
        ++id;
    }

    void IdCreator::reset()
    {
        id = 0;
    }

    int IdCreator::getAnId() const
    {
        return id;
    }
}