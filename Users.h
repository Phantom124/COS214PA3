#ifndef USERS_H
#define USERS_H

#include "Chatroom.h" 

class Command;

class Users
{
    protected:
        vector<ChatRoom*> chatRooms;
        string name;
        vector<Command*> commandQueue ;
      
    public: 
        Users(string name);
        void send(string message,ChatRoom room);
        void receive(string message,Users fromUser,ChatRoom room);
        void addCommand(Command command);
        void executeAll();
        string getName();
    
};




#endif