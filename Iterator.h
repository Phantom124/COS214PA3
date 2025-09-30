#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {
    private:
        int currPos;
    public:
        virtual bool isDone() = 0;
};

#endif