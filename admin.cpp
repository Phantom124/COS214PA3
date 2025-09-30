#include "admin.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

admin::admin(string name,ChatRoom* room):Users(name,room){}
void admin::send(string message,ChatRoom* room){
    Command* executer;
    bool flag = false ;
    for(vector<Command*>::iterator it = commandQueue.begin();it != commandQueue.end();++it){
         if(*it==(new SendMessageCommand(room,message,this))){
            executer = *it;
            flag = true ;
            break;
        }
    }
    if(flag == true){
        executer->execute();
    }
    executer = new SendMessageCommand(room,message,this);
    executer->execute();
}
void admin::receive(string message,Users* fromUser,ChatRoom* room){
    Command* executer ;
    bool flag = false;
    for(vector<Command*>::iterator it = commandQueue.begin() ;it != commandQueue.end();it++ ){
        if(*it==(new LogMessageCommand(room,message,this))){
            executer = *it;
            flag =true ;
            break;
        }
    }
    if(flag == true){
        executer->execute();
    }
    executer=new LogMessageCommand(room,message,this);
    executer->execute();

}

void admin::addCommand(Command* command){
    commandQueue.push_back(command);
}
void admin::removeUser(Users* toRemove,ChatRoom* room){
    room->removeUser(toRemove);
}

void admin::executeAll(){
    for(vector<Command*>::iterator it = commandQueue.begin() ; it != commandQueue.end();++it){
        (*it)->execute();
    }
}

