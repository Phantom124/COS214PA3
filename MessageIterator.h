#ifndef MESSAGE_ITERATOR_H
#define MESSAGE_ITERATOR_H

#include "Iterator.h"
#include "MessageVector.h"

class MessageIterator : public Iterator {
    private:
        int currPos;
        MessageVector* vec;
    public:
        MessageIterator(MessageVector* vec, const int currPos = 0);
        ~MessageIterator();
        virtual void addMessage(string* u);
        virtual void removeMessage(string* u);
        virtual string* first();
        virtual string* next();
        virtual bool isDone();
        virtual string* currentItem();
};
 
#endif