#ifndef USER_ITERATOR_H
#define USER_ITERATOR_H

#include "Iterator.h"

class UserIterator : public Iterator {
    private:
        int currPos;
        UserVector* vector;
    public:
        UserIterator(UserVector* vector, const int currPos = 0);
        ~UserIterator();
        virtual void addUser(Users* u);
        virtual void removeUser(Users* u);
        virtual void removeUser(string name);
        virtual Users* first();
        virtual Users* next();
        virtual bool isDone();
        virtual Users* currentItem();
};

#include "UserIterator.cpp"

#endif