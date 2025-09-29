#ifndef SEND_MESSAGE_COMMAND_H
#define SEND_MESSAGE_COMMAND_H

#include "Command.h"

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom* room, string message, Users* fromUser);
        virtual void execute();
};

#endif