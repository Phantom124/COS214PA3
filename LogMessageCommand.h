#ifndef LOG_MESSAGE_COMMAND_H
#define LOG_MESSAGE_COMMAND_H

#include "Command.h"

class LogMessageCommand : public Command {
    public: 
        virtual void execute();
};

#endif