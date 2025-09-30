#include "dogorithm.h"

#include "Users.h"

void Dogorithm::registerUser(Users* users){
    this->users.push_back(users);
    cout<<users->getName() <<" has join the roomD"<<endl;
}

void Dogorithm::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
void Dogorithm::saveMessage(string message,Users* fromUser){
    string m = fromUser->getName()+ message;
    this->chatHistory.push_back(&m);
    cout<<"message saved!"<<endl;
}

void Dogorithm::removeUser(Users* user){
       for(vector<Users*>::iterator it = users.begin(); it != users.end(); ++it){
            if(*it == user){
            cout<<"user :"<<user->getName() <<" is leaving the room"<<endl;
            users.erase(it);
            break;
            }   
       }
}