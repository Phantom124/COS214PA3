/**
 * @file admin.cpp
 * @brief Concrete Users implementation representing an admin participant.
 */

#ifndef ADMIN_CPP
#define ADMIN_CPP

#include "admin.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

/**
 * @brief Construct a new admin user.
 */
admin::admin(string name,ChatRoom* room):Users(name,room){}
/**
 * @brief Send a message to a room via command execution.
 */
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
/**
 * @brief Receive a message and log it.
 */
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

/**
 * @brief Queue a command for later execution.
 */
void admin::addCommand(Command* command){
    commandQueue.push_back(command);
}
/**
 * @brief Remove a user from the given room.
 */
void admin::removeUser(Users* toRemove,ChatRoom* room){
    room->removeUser(toRemove);
}

/**
 * @brief Execute all commands in the queue.
 */
void admin::executeAll(){
    for(vector<Command*>::iterator it = commandQueue.begin() ; it != commandQueue.end();++it){
        (*it)->execute();
    }
}

#endif