/**
 * @file jerry.cpp
 * @brief Concrete Users implementation representing a normal participant.
 */
#include "jerry.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"


/**
 * @brief Construct a new jerry user.
 * @param name Display name.
 * @param room Optional room to join upon creation.
 */
jerry::jerry(string name,ChatRoom* room):Users(name,room){}

/**
 * @brief Send a message to a room via command execution.
 * @param message Message text.
 * @param room Target chat room.
 */
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
/**
 * @brief Receive a message and log it via command execution.
 * @param message Message text.
 * @param fromUser Sender reference.
 * @param room Originating chat room.
 */
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
/**
 * @brief Queue a command for later execution.
 * @param command Command to enqueue.
 */
void jerry::addCommand(Command* command){
    commandQueue.push_back(command);

}
/**
 * @brief Execute all queued commands in order.
 */
void jerry::executeAll(){
    for(vector<Command*>::iterator it = commandQueue.begin() ; it != commandQueue.end();++it){
        (*it)->execute();
    }
}