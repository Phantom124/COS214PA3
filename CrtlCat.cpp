/**
 * @file CrtlCat.cpp
 * @brief Concrete ChatRoom implementation named CrtlCat.
 */
#include "CrtlCat.h"
#include "Users.h"

/**
 * @brief Register a new user in the room using the iterator helper.
 */
void CrtlCat::registerUser(Users* user){
    // this->users.push_back(users);
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());
    userIt->addUser(user);
    delete userIt;
    cout<<user->getName() <<" has join the roomC"<<endl;
}

/**
 * @brief Broadcast a message and persist it.
 */
void CrtlCat::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
/**
 * @brief Save a message to this room's history.
 */
void CrtlCat::saveMessage(string message,Users* fromUser){
    string* m = new string(fromUser->getName()+ message);
    
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(chatHistory->createIterator());
    mIt->addMessage(m);
    delete mIt;

    cout<<"message saved!"<<endl;
}

/**
 * @brief Remove a user from the room.
 */
void CrtlCat::removeUser(Users* user){
//    for(vector<Users*>::iterator it = users.begin(); it != users.end(); ++it){
//         if(*it == user){
//         users.erase(it);
//         break;
//         }   
//    }

    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());
    userIt->removeUser(user);
    cout<<"user :"<<user->getName() <<" is leaving the room"<<endl;
    delete userIt;
}