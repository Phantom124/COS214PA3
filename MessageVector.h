#ifndef MESSAGE_VECTOR_H
#define MESSAGE_VECTOR_H

#include <vector>
#include <string>
#include "Aggregate.h"

using namespace std;

class Iterator;
class MessageIterator;

class MessageVector : public Aggregate {
    friend class MessageIterator;
    private:
        vector<string*> msgs;
    public:
        ~MessageVector();
        virtual Iterator* createIterator();
};

#endif 