/**
 * @file UserIterator.cpp
 * @brief Implements iteration and basic CRUD operations over a collection of Users.
 * @details This file defines the concrete iterator used to traverse and manage
 *          a `UserVector` aggregate. It provides utilities to add and remove
 *          users and to iterate with first/next/isDone/currentItem.
 */
#ifndef USER_ITERATOR_CPP
#define USER_ITERATOR_CPP

#include <iostream>
#include "UserIterator.h"
#include "UserVector.h"
#include "Users.h"

using namespace std;

/**
 * @brief Construct a new UserIterator.
 * @param vector Pointer to the underlying `UserVector` aggregate.
 * @param currPos Starting position in the aggregate (default 0).
 */
UserIterator::UserIterator(UserVector* vector, const int currPos = 0){
    this->vector = vector;
    this->currPos = currPos;
}

/**
 * @brief Destroy the UserIterator object.
 */
UserIterator::~UserIterator(){

}

/**
 * @brief Add a user to the aggregate if the username is unique.
 * @param u Pointer to the user to add.
 */
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

/**
 * @brief Remove a specific user instance from the aggregate.
 * @param u Pointer to the user to remove.
 */
void UserIterator::removeUser(Users* u){
    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        if (u == *it){
            vector->userVec.erase(it);
        } 
    }
}

/**
 * @brief Remove a user by name from the aggregate.
 * @param name The username to match when removing.
 */
void UserIterator::removeUser(string name){
    for (std::vector<Users*>::iterator it = vector->userVec.begin(); it < vector->userVec.end(); it++){
        if (name == (*it)->getName()){
            vector->userVec.erase(it);
        } 
    }
}

/**
 * @brief Get the first user in the aggregate and reset the iterator.
 * @return Users* Pointer to the first user, or nullptr if empty.
 */
Users* UserIterator::first(){
    if (vector->userVec.size() <= 0){
        return nullptr;
    }
    this->currPos = 0;
    return vector->userVec[0];
}

/**
 * @brief Advance the iterator and return the next user.
 * @return Users* Pointer to the next user, or nullptr if past the end.
 */
Users *UserIterator::next(){
    this->currPos++;
    if (vector->userVec.size() <= this->currPos){
        return nullptr;
    }
    return vector->userVec[this->currPos];
}

/**
 * @brief Check whether the iterator has reached or passed the end.
 * @return true if there are no more items to iterate; false otherwise.
 */
bool UserIterator::isDone(){
    return (vector->userVec.size() <= this->currPos);
}

/**
 * @brief Get the current user at the iterator's position.
 * @return Users* Pointer to the current user, or nullptr if out of bounds.
 */
Users* UserIterator::currentItem(){
    if (vector->userVec.size() > 0 && this->currPos){
        return nullptr;
    }
    return vector->userVec[this->currPos];
}

#endif