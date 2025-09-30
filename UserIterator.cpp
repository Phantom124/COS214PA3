#ifndef USER_ITERATOR_CPP
#define USER_ITERATOR_CPP

#include <iostream>
#include "UserIterator.h"
#include "UserVector.h"
#include "Users.h"

using namespace std;

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
    string newName = u->getName();

    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        if (u->getName() == (*it)->getName()){
            cout << "Please enter a different username. That one already exists." << endl;
            return;
        }
    }

    vector->userVec.push_back(u);
}

void UserIterator::removeUser(Users* u){
    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        if (u == *it){
            vector->userVec.erase(it);
        }
    }
}

Users* UserIterator::first(){
    if (vector->userVec.size() <= 0){
        return nullptr;
    }
    this->currPos = 0;
    return vector->userVec[0];
}

Users *UserIterator::next(){
    this->currPos++;
    if (vector->userVec.size() <= this->currPos){
        return nullptr;
    }
    return vector->userVec[this->currPos];
}

bool UserIterator::isDone(){
    return (vector->userVec.size() <= this->currPos);
}

Users* UserIterator::currentItem(){
    if (vector->userVec.size() > 0 && this->currPos){
        return nullptr;
    }
    return vector->userVec[this->currPos];
}

#endif