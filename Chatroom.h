#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Users;
class UserVector;
class MessageVector;
class Iterator;

class ChatRoom {

    protected:
        // vector<Users*> users;
        // vector<string*> chatHistory;
        UserVector* users;
        MessageVector* chatHistory;

    public:
        virtual void registerUser(Users* user)=0;
        virtual void sendMessage(string message,Users* fromUser);
        virtual void saveMessage(string message ,Users* fromUser);
        virtual void removeUser(Users* user)=0;
        
};

#endif