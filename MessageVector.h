#ifndef MESSAGE_VECTOR_H
#define MESSAGE_VECTOR_H

#include <vector>
#include <string>
#include "Aggregate.h"
#include "MessageIterator.h"

using namespace std;

class MessageVector : public Aggregate {
    friend class MessageIterator;
    private:
        vector<string*> msgs;
    public:
        virtual Iterator* createIterator();
};

#include "MessageVector.cpp"

#endif 