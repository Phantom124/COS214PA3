#ifndef VECTOR_H
#define VECTOR_H

#include "Aggregate.h"

class Vector {

    virtual Iterator* createIterator() = 0; 

};

#endif