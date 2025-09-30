#ifndef LOGSTRATEGY_H
#define LOGSTRATEFY_H

#include "strategy.h"
#include <string>
using namespace std;
class logStrategy:public strategy{
    public:
        void handleMessage(string message,Users* fromUsers,ChatRoom* room)override;
};
#endif