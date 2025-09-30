#ifndef USER_ITERATOR_H
#define USER_ITERATOR_H

#include "Iterator.h"

class Users;
class UserVector;

class UserIterator : public Iterator {
    private:
        int currPos;
        UserVector* vec;
    public:
        UserIterator(UserVector* vec, const int currPos = 0);
        ~UserIterator();
        virtual void addUser(Users* u);
        virtual void removeUser(Users* u);
        virtual void removeUser(string name);
        virtual Users* first();
        virtual Users* next();
        virtual bool isDone();
        virtual Users* currentItem();
};


#endif