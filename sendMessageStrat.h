#ifndef SENDMESSAGESTRAT_H
#define SENDMESSAGESTRAT_H

#include "strategy.h"

class SendMessageStrat:public strategy{
    public:
        void handleMessage(string message,Users* fromUsers,ChatRoom* room) override; 
};

#endif