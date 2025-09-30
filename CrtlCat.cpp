#include "CrtlCat.h"
#include "Users.h"

void CrtlCat::registerUser(Users* users){
    this->users.push_back(users);
    cout<<users->getName() <<" has join the roomC"<<endl;
}

void CrtlCat::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
void CrtlCat::saveMessage(string message,Users* fromUser){
    string m = fromUser->getName()+ message;
    this->chatHistory.push_back(&m);
    cout<<"message saved!"<<endl;
}

void CrtlCat::removeUser(Users* user){
       for(vector<Users*>::iterator it = users.begin(); it != users.end(); ++it){
            if(*it == user){
            cout<<"user :"<<user->getName() <<" is leaving the room"<<endl;
            users.erase(it);
            break;
            }   
       }
}