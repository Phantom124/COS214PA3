/**
 * @file LogMessageCommand.cpp
 * @brief Command object that persists a message to the room history.
 */
#include "LogMessageCommand.h"

/**
 * @brief Construct a new LogMessageCommand.
 * @param room Target chat room.
 * @param message Message to log.
 * @param fromUser Originating user reference.
 */
LogMessageCommand::LogMessageCommand(ChatRoom* room, string message, Users* fromUser):Command(room,message,fromUser)
{}
/**
 * @brief Execute the command by delegating to ChatRoom::saveMessage.
 */
void LogMessageCommand::execute(){
    room->saveMessage(message, fromUser);
}