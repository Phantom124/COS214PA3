#ifndef USER_VECTOR_H
#define USER_VECTOR_H

#include <vector>
#include "Aggregate.h"
#include "Users.h"
#include "UserIterator.h"

using namespace std;

class UserVector : public Aggregate {
    friend class UserIterator;
    private:
        vector<Users*> userVec;
    public:
        virtual Iterator* createIterator();
};

#include "UserVector.cpp"

#endif