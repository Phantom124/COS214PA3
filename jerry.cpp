/**
 * @file jerry.cpp
 * @brief Concrete Users implementation representing a normal participant.
 */
#ifndef JERRY_CPP
#define JERRY_CPP

#include "jerry.h"
#include "Command.h"



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
    strat->handleMessage(message,this,room);
    
}
/**
 * @brief sets the stratey for sending messages 
 * @param strategy
 */
void jerry::setStrat(strategy* s){
    this->strat = s;
}
/**
 * @brief Receive a message and log it via command execution.
 * @param message Message text.
 * @param fromUser Sender reference.
 * @param room Originating chat room.
 */
void jerry::receive(string message,Users* fromUser,ChatRoom* room){
    strat->handleMessage(message,this,room);
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

#endif