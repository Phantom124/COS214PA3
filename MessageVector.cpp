/**
 * @file MessageVector.cpp
 * @brief Concrete aggregate for storing chat messages.
 */
#ifndef MESSAGE_VECTOR_CPP
#define MESSAGE_VECTOR_CPP

#include "MessageVector.h"
#include "MessageIterator.h"

/**
 * @brief Destroy the MessageVector and free owned message strings.
 */
MessageVector::~MessageVector(){
    for (std::vector<string*>::iterator it = msgs.begin(); it < msgs.end(); it++){
        delete (*it);
    }
}

/**
 * @brief Create a new iterator for traversing messages.
 */
Iterator *MessageVector::createIterator(){
    Iterator* it = new MessageIterator(this, 0);
    return it;
}

#endif 