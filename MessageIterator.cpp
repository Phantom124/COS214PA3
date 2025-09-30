/**
 * @file MessageIterator.cpp
 * @brief Iterator implementation for traversing and mutating a message store.
 */
#ifndef MESSAGE_ITERATOR_CPP
#define MESSAGE_ITERATOR_CPP

#include "MessageIterator.h"

/**
 * @brief Construct a new MessageIterator.
 * @param vector Backing aggregate.
 * @param currPos Initial position within the vector.
 */
MessageIterator::MessageIterator(MessageVector *vector, const int currPos){
    this->vector = vector;
    this->currPos = currPos;
}

/**
 * @brief Destroy the MessageIterator object.
 */
MessageIterator::~MessageIterator(){
    
}

/**
 * @brief Append a message pointer to the aggregate.
 * @param u Pointer to message string (ownership transferred to aggregate).
 */
void MessageIterator::addMessage(string *u){
    vector->msgs.push_back(u);
}

/**
 * @brief Remove a message pointer from the aggregate if found.
 * @param u Pointer to message string to remove.
 */
void MessageIterator::removeMessage(string *u){
    for (std::vector<string*>::iterator it = vector->msgs.begin(); it < vector->msgs.end(); it++){
        if (u == (*it)){
            vector->msgs.erase(it);
        } 
    }
}

/**
 * @brief Reset and return the first message.
 * @return string* Pointer to first message, or nullptr if empty.
 */
string* MessageIterator::first(){
    if (vector->msgs.size() <= 0){
        return nullptr;
    }
    this->currPos = 0;
    return vector->msgs[0];
}

/**
 * @brief Advance and return the next message.
 * @return string* Pointer to next message, or nullptr if at end.
 */
string *MessageIterator::next(){
    this->currPos++;
    if (vector->msgs.size() <= this->currPos){
        return nullptr;
    }
    return vector->msgs[this->currPos];
}

/**
 * @brief Determine if iteration has completed.
 * @return true when no more messages remain; false otherwise.
 */
bool MessageIterator::isDone(){
    return (vector->msgs.size() <= this->currPos);
}

/**
 * @brief Get the current message at the iterator position.
 * @return string* Pointer to current message, or nullptr if invalid position.
 */
string* MessageIterator::currentItem(){
    if (vector->msgs.size() > 0 && this->currPos){
        return nullptr;
    }
    return vector->msgs[this->currPos];
}

#endif