#ifndef USER_ITERATOR_CPP
#define USER_ITERATOR_CPP

#include "UserIterator.h"
#include "UserVector.h"
#include "Users.h"

UserIterator::UserIterator(UserVector* vector, const int currPos = 0){
    this->vector = vector;
    this->currPos = currPos;
}

UserIterator::~UserIterator(){

    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        delete (*it);
    }

    //Leaving the deallocation of pointer to UserVector to whatever client is using it

}

void UserIterator::addUser(Users* u){
    vector->userVec.push_back(u);
    //Possibly add a check to see if the name exists, thus only allowing unique usernames
}

void UserIterator::removeUser(Users* u){
    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        if (u == *it){
            vector->userVec.erase(it);
        }
    }
}















__bswap_16


UserIterator::first()
{
}

Users* UserIterator::currentItem(){
    return vector->userVec[this->currPos];
}

#endif