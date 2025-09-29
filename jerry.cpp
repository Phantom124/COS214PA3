#include "jerry.h"
#include "Command"
jerry::jerry(string name,ChatRoom* room):Users(name,room){}

void jerry::send(string message,ChatRoom room){
    Command* executer ;
    for(vector<Command*>::iterator it = commandQueue.begin() ;it != commandQueue.end();it++ ){
        if(*it==sendMessageCommand){
            executer = it;
        }
    }
    // room.sendMessage(message,this);//or is this done in the command ??
    
}