#include "CrtlCat.h"
#include "Users.h"

void CrtlCat::registerUser(Users* user){
    // this->users.push_back(users);
    this->users->createIterator();
    UserIterator* userIt = dynamic_cast<UserIterator*>(users->createIterator());
    userIt->addUser(user);
    delete userIt;
    cout<<user->getName() <<" has join the roomC"<<endl;
}

void CrtlCat::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
void CrtlCat::saveMessage(string message,Users* fromUser){
    string* m = new string(fromUser->getName()+ message);
    
    MessageIterator* mIt = dynamic_cast<MessageIterator*>(chatHistory->createIterator());
    mIt->addMessage(m);
    delete mIt;

    cout<<"message saved!"<<endl;
}

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