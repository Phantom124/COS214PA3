#ifndef ADMIN_H
#define ADMIN_H

#include "Users.h"
class admin:protected Users
{
    public:
        admin(string name,ChatRoom* room);
        void send(string message,ChatRoom* room);
        void receive(string message,Users* fromUser,ChatRoom* room);
        void addCommand(Command* command);
        void executeAll();
   
};


#endif //ADMIN_H