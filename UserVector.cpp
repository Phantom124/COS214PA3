#ifndef USER_VECTOR_CPP
#define USER_VECTOR_CPP 

#include "UserVector.h"
#include "UserIterator.h"

UserVector::~UserVector(){
    for (std::vector<Users*>::iterator it = userVec.begin(); it < userVec.end(); it++){
        delete (*it);
    }

}

Iterator *UserVector::createIterator(){
    return new UserIterator(this, 0);
}

#endif