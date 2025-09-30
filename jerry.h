#ifndef JERRY_H 
#define JERRY_H 

#include "Users.h"
class jerry:public Users{

    public:
        jerry(string name,ChatRoom* room);
        void setStrat(strategy* s);
        void send(string message,ChatRoom* room) ;
        void receive(string message,Users* fromUser,ChatRoom* room) ;
        void addCommand(Command* command) ;
        void executeAll();

};

#endif