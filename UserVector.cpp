/**
 * @file UserVector.cpp
 * @brief Concrete aggregate storing Users and creating UserIterator instances.
 */
#ifndef USER_VECTOR_CPP
#define USER_VECTOR_CPP 

#include "UserVector.h"
#include "UserIterator.h"

/**
 * @brief Destroy the UserVector and release owned Users.
 */
UserVector::~UserVector(){
    for (std::vector<Users*>::iterator it = userVec.begin(); it < userVec.end(); it++){
        delete (*it);
    }

}

/**
 * @brief Create a new iterator for this aggregate.
 * @return Iterator* Newly allocated iterator positioned at 0.
 */
Iterator *UserVector::createIterator(){
    cout << "Is it even getting here? -- 1" << endl;
    Iterator* it = new UserIterator(this, 0);
    cout << "Is it even getting here? -- 2" << endl;

    return it;
}

#endif