#ifndef MESSAGE_VECTOR_CPP
#define MESSAGE_VECTOR_CPP

#include "MessageVector.h"
#include "MessageIterator.h"

MessageVector::~MessageVector(){
    for (std::vector<string*>::iterator it = msgs.begin(); it < msgs.end(); it++){
        delete (*it);
    }
}

Iterator *MessageVector::createIterator()
{
    return new MessageIterator(this, 0);
}

#endif 