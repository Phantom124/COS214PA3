#ifndef COMMAND_CPP
#define COMMAND_CPP

#include <string>
#include "Command.h"
#include "Chatroom.h"
#include "Users.h"

Command::Command(ChatRoom* room, string message, Users* fromUser) {
    this->room = room;
    this->message = message;
    this->fromUser = fromUser;
}



#endif