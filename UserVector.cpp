#ifndef USER_VECTOR_CPP
#define USER_VECTOR_CPP 

#include "UserVector.h"
#include "UserIterator.h"

Iterator *UserVector::createIterator(){
    return new UserIterator(this, 0);
}

#endif