#include "Chatroom.h"
#include "Users.h"

void ChatRoom::sendMessage(string message, Users* fromUser){
    
    // for (std::vector<Users*>::iterator it = users.begin(); it < users.end(); it++){
    //     (*it)->receive(message, fromUser, this);
    // }
    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());

    while (!userIt->isDone()){
        Users* user = userIt->currentItem();
        user->receive(message, fromUser, this);
        userIt->next();
    }

    delete userIt;

}

void ChatRoom::saveMessage(string message, Users* fromUser){
    string* msgPointer = new string(message);
    // chatHistory.push_back(msgPointer);
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(chatHistory->createIterator());
    mIt->addMessage(msgPointer);
    delete mIt;
}
