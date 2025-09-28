#ifndef CHATROOM_H
#define CHATROOM_H

#include <vector>
#include <string>
using namespace std;
class Users;

class ChatRoom {

    private:
        vector<Users*> users;
        vector<string*> chatHistroy;
            
    public:
        void registerUser(Users user);
        void sendMessage(string message,Users fromUseer);
        void saveMesssage(string message ,Users fromUser);
        void removeUser(Users user);
        
};

#endif