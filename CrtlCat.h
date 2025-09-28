#ifndef CRTLCAT_H
#define CRTLCAT_H


#include "Chatroom.h"


class CrtlCat : public ChatRoom{
    private:
        vector<Users*> users;
        vector<string*> chatHistroy;
            
    public:
        void registerUser(Users* user);
        void sendMessage(string message,Users* fromUser);
        void saveMessage(string message ,Users* fromUser);
        void removeUser(Users* user);


};



#endif //CRTLCAT_H