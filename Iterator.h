#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {
    private:
        int currPos;
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual void isDone() = 0;
        virtual Users* currentItem() = 0;
};

#endif