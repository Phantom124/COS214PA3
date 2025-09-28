#ifndef COMMAND_H
#define COMMAND_H

#include "Chatroom.h"
#include <string>
#include "Users.h"

class Command {
    protected:
        ChatRoom* room;
        string message;
        Users* fromUser;
    public:
        Command(ChatRoom* room, string message, Users* fromUser);
        virtual void execute() = 0;
};

#endif 