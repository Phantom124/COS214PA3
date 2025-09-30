/**
 * @file Command.cpp
 * @brief Base Command class constructor implementation.
 */
#ifndef COMMAND_CPP
#define COMMAND_CPP

#include <string>
#include "Command.h"
#include "Chatroom.h"
#include "Users.h"

/**
 * @brief Construct a new Command.
 * @param room Target chat room.
 * @param message Message payload.
 * @param fromUser Sender reference.
 */
Command::Command(ChatRoom* room, string message, Users* fromUser) {
    this->room = room;
    this->message = message;
    this->fromUser = fromUser;
}



#endif