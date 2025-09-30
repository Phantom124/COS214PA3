#include "Chatroom.h"
#include "Users.h"

void ChatRoom::sendMessage(string message, Users* fromUser){
    
    for (std::vector<Users*>::iterator it = users.begin(); it < users.end(); it++){
        (*it)->receive(message, fromUser, this);
    }
}

void ChatRoom::saveMessage(string message, Users* fromUser){
    string* msgPointer = new string(message);
    chatHistory.push_back(msgPointer);
}
