#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>
using namespace std;
class Users;

class ChatRoom {

    private:
        vector<Users*> users;
        vector<string*> chatHistory;
            
    public:
        void registerUser(Users user);
        void sendMessage(string message,Users fromUser);
        void saveMessage(string message ,Users fromUser);
        void removeUser(Users user);
        
};

#endif