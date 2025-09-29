#include "admin.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

admin::admin(string name,ChatRoom* room):Users(name,room){}
void admin::send(string message,ChatRoom* room){
    Command* executer;
    for(vector<Command*>::iterator it = commandQueue.begin();it != commandQueue.end();++it){
         if(*it==(new SendMessageCommand(room,message,this))){
            executer = *it;
            break;
        }
    }
    executer->execute();
}
