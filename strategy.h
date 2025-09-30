#ifndef STRATEGY_H
#define STRATEGY_H

#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"


class strategy
{
    public:
        void handleMessage();
};
#endif //STRATEGY