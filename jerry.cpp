#include "jerry.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"


jerry::jerry(string name,ChatRoom* room):Users(name,room){}

void jerry::send(string message,ChatRoom* room){
    Command* executer ;
    bool flag = false;
    for(vector<Command*>::iterator it = commandQueue.begin() ;it != commandQueue.end();it++ ){
        if(*it==(new SendMessageCommand(room,message,this))){
            executer = *it;
            flag = true;
            break;
        }
    }
    // room.sendMessage(message,this);//or is this done in the command ??
    // executer->execute();
    if(flag == true){
        executer->execute();
    }
    executer = new SendMessageCommand(room,message,this);
    executer->execute();
    
}
void jerry::receive(string message,Users* fromUser,ChatRoom* room){
    // string* ptr = new string(message);
    // room->saveMessage(message,fromUser);
     Command* executer ;
      bool flag = false ;
    for(vector<Command*>::iterator it = commandQueue.begin() ;it != commandQueue.end();it++ ){
        if(*it==(new LogMessageCommand(room,message,this))){
            executer = *it;
            flag=true;
            break;
        }
    }
    // room.sendMessage(message,this);//or is this done in the command ??
    if(flag == true){
        executer->execute();
    }
    executer = new LogMessageCommand(room,message,this);
    executer->execute();
    // executer->execute();
}
void jerry::addCommand(Command* command){
    commandQueue.push_back(command);

}
void jerry::executeAll(){
    for(vector<Command*>::iterator it = commandQueue.begin() ; it != commandQueue.end();++it){
        (*it)->execute();
    }
}