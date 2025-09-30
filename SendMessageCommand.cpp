/**
 * @file SendMessageCommand.cpp
 * @brief Command that broadcasts a message through a ChatRoom.
 */
#ifndef SEND_MESSAGE_COMMAND_CPP
#define SEND_MESSAGE_COMMAND_CPP

#include "SendMessageCommand.h"

/**
 * @brief Construct a new SendMessageCommand.
 * @param room Target chat room.
 * @param message Message payload to send.
 * @param fromUser Sender reference.
 */
SendMessageCommand::SendMessageCommand(ChatRoom* room, string message, Users* fromUser)
    : Command(room, message, fromUser){}

/**
 * @brief Execute the command by delegating to ChatRoom::sendMessage.
 */
void SendMessageCommand::execute(){
    room->sendMessage(message, fromUser);   
}

#endif