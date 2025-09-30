/**
 * @file admin.cpp
 * @brief Concrete Users implementation representing an admin participant.
 */

#ifndef ADMIN_CPP
#define ADMIN_CPP

#include "admin.h"
#include "Command.h"

/**
 * @brief Construct a new admin user.
 */
admin::admin(string name,ChatRoom* room):Users(name,room){}
/**
 * @brief Send a message to a room via command execution.
 */
void admin::send(string message,ChatRoom* room){
    strat->handleMessage(message,this,room);
}
void admin::setStrat(strategy* s){
    this->strat = s;
}
/**
 * @brief Receive a message and log it.
 */
void admin::receive(string message,Users* fromUser,ChatRoom* room){
    strat->handleMessage(message,this,room);

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