#ifndef USERS_H
#define USERS_H

#include "Chatroom.h"
// #include "Command.h"
class Command ;

class Command;

class Users
{
    protected:
        vector<ChatRoom*> chatRooms;
        string name;
        vector<Command*> commandQueue ;
      
    public: 
        Users(string name,ChatRoom* room);
        string getName();
        virtual void send(string message,ChatRoom room)=0;
        virtual void receive(string message,Users fromUser,ChatRoom room);
        virtual void addCommand(Command command)=0;
        virtual void executeAll()=0;
    
};




#endif