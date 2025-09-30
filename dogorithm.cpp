/**
 * @file dogorithm.cpp
 * @brief Concrete ChatRoom variant implementing Dogorithm behavior.
 */

#ifndef DOGORITHM_CPP
#define DOGORITHM_CPP
#include "dogorithm.h"
#include "UserIterator.h"
#include "UserVector.h"
#include "MessageIterator.h"
#include "MessageVector.h"

#include "Users.h"

/**
 * @brief Register a user with the room using the iterator facade.
 * @param users The user to register (ownership not transferred).
 */
void Dogorithm::registerUser(Users* users){
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(this->users->createIterator());
    userIt->addUser(users);
    delete userIt;
    cout<<users->getName() <<" has join the roomD"<<endl;
}

/**
 * @brief Broadcast a message from a user to the room and save it.
 * @param message Message text.
 * @param fromUser Sender.
 */
void Dogorithm::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
/**
 * @brief Persist a message to chat history via MessageIterator.
 * @param message Message text.
 * @param fromUser Sender.
 */
void Dogorithm::saveMessage(string message,Users* fromUser){
    string* m = new string(fromUser->getName()+ message);
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(this->chatHistory->createIterator());
    mIt->addMessage(m);
    delete mIt;
    cout<<"message saved!"<<endl;
}

/**
 * @brief Remove an existing user from the room.
 * @param user The user to remove.
 */
void Dogorithm::removeUser(Users* user){
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());
    cout<<"user :"<<user->getName() <<" is leaving the room"<<endl;
    userIt->removeUser(user);
    delete userIt;
}

#endif