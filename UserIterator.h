#ifndef USER_ITERATOR_H
#define USER_ITERATOR_H

#include "Aggregate.h"

class UserIterator : public Aggregate {
    private:
        int currPos;
        UserVector* vector;
    public:
        UserIterator(UserVector* vector, const int currPos = 0);
        ~UserIterator();
        virtual void addUser(Users* u);
        virtual void removeUser(Users* u);
        virtual void first();
        virtual void next();
        virtual void isDone();
        virtual Users* currentItem();
};

#endif