#ifndef USER_VECTOR_H
#define USER_VECTOR_H

#include <vector>
#include "Aggregate.h"
// #include "Users.h"
// #include "UserIterator.h"

class Users;
class Iterator;

using namespace std;

class UserVector : public Aggregate {
    friend class UserIterator;
    private:
        vector<Users*> userVec;
    public:
        ~UserVector();
        virtual Iterator* createIterator();
};

#endif