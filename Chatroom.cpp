/**
 * @file Chatroom.cpp
 * @brief Default ChatRoom method implementations for broadcasting and saving messages.
 */

 #ifndef CHATROOM_CPP
 #define CHATROOM_CPP
#include "Chatroom.h"
#include "Users.h"
#include "UserIterator.h"
#include "UserVector.h"
#include "MessageVector.h"
#include "MessageIterator.h"

/**
 * @brief Broadcast a message to all registered users via the iterator.
 * @param message The message text.
 * @param fromUser The sender of the message.
 */
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

/**
 * @brief Save a message to the room's history.
 * @param message The message text.
 * @param fromUser The original sender (unused in this default implementation).
 */
void ChatRoom::saveMessage(string message, Users* fromUser){
    string* msgPointer = new string(message);
    // chatHistory.push_back(msgPointer);
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(chatHistory->createIterator());
    mIt->addMessage(msgPointer);
    delete mIt;
}
#endif