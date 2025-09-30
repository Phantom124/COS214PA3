#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "Chatroom.h"
class Dogorithm:public ChatRoom{
    public:
        void registerUser(Users* user);
        void sendMessage(string message,Users* fromUser);
        void saveMessage(string message ,Users* fromUser);
        void removeUser(Users* user);


};


#endif