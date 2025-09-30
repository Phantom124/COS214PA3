#include "dogorithm.h"

#include "Users.h"

void Dogorithm::registerUser(Users* users){
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(this->users->createIterator());
    userIt->addUser(users);
    delete userIt;
    cout<<users->getName() <<" has join the roomD"<<endl;
}

void Dogorithm::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
void Dogorithm::saveMessage(string message,Users* fromUser){
    string* m = new string(fromUser->getName()+ message);
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(this->chatHistory->createIterator());
    mIt->addMessage(m);
    delete mIt;
    cout<<"message saved!"<<endl;
}

void Dogorithm::removeUser(Users* user){
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());
    userIt->removeUser(user);
    delete userIt;
}