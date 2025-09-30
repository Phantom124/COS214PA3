#ifndef MESSAGE_VECTOR_CPP
#define MESSAGE_VECTOR_CPP

#include "MessageVector.h"
#include "MessageIterator.h"

Iterator* MessageVector::createIterator(){
    return new MessageIterator(this, 0);
}

#endif 