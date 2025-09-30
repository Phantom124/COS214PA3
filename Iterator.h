#ifndef ITERATOR_H
#define ITERATOR_H

#include "Users.h"

class Iterator {
    private:
        int currPos;
    public:
        virtual ~Iterator(){};
        virtual bool isDone() = 0;
};

#endif