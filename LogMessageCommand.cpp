#include "LogMessageCommand.h"

LogMessageCommand::LogMessageCommand(ChatRoom* room, string message, Users* fromUser):Command(room,message,fromUser)
{}
void LogMessageCommand::execute(){
    room->saveMessage(message, fromUser);
}