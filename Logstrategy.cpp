/**
 * @file Logstrategy.cpp
 * @brief Strategy implementation that logs messages using a Command.
 */
#include "Logstrategy.h"

/**
 * @brief Handle an incoming message by logging it via LogMessageCommand.
 * @param message The message text.
 * @param fromUsers The originator user pointer.
 * @param room The chat room where the message belongs.
 */
void logStrategy::handleMessage(string message,Users* fromUsers,ChatRoom* room){
    LogMessageCommand logStrategy(room,message,fromUsers);
    logStrategy.execute();
}