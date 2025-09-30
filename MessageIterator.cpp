#ifndef MESSAGE_ITERATOR_CPP
#define MESSAGE_ITERATOR_CPP

#include "MessageIterator.h"

MessageIterator::MessageIterator(MessageVector *vector, const int currPos){
    this->vector = vector;
    this->currPos = currPos;
}

MessageIterator::~MessageIterator(){
    for (std::vector<string*>::iterator it = vector->msgs.begin(); it < vector->msgs.end(); it++){
        delete (*it);
    }
}

void MessageIterator::addMessage(string *u){
    vector->msgs.push_back(u);
}

void MessageIterator::removeMessage(string *u){
    for (std::vector<string*>::iterator it = vector->msgs.begin(); it < vector->msgs.end(); it++){
        if (u == (*it)){
            vector->msgs.erase(it);
        } 
    }
}

string* MessageIterator::first(){
    if (vector->msgs.size() <= 0){
        return nullptr;
    }
    this->currPos = 0;
    return vector->msgs[0];
}

string *MessageIterator::next(){
    this->currPos++;
    if (vector->msgs.size() <= this->currPos){
        return nullptr;
    }
    return vector->msgs[this->currPos];
}

bool MessageIterator::isDone(){
    return (vector->msgs.size() <= this->currPos);
}

string* MessageIterator::currentItem(){
    if (vector->msgs.size() > 0 && this->currPos){
        return nullptr;
    }
    return vector->msgs[this->currPos];
}

#endif