#include "CrtlCat.h"
#include "Users.h"

void CrtlCat::registerUser(Users* users){
    this->users.push_back(users);
    cout<<users->getName() <<" has join the room"<<endl;
}

void CrtlCat::sendMessage(string message,Users* fromUser){ 
    cout<<"["<<fromUser->getName()<<"]"<<message<<endl;
    saveMessage(message,fromUser);//save the chat after it has been sent

}
void CrtlCat::saveMessage(string message,Users* fromUser){
    string m = fromUser->getName()+ message;
    this->chatHistroy.push_back(&m);
    cout<<"message saved!"<<endl;
}