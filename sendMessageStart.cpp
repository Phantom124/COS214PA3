/**
 * @file sendMessageStart.cpp
 * @brief Strategy that sends a message using the SendMessageCommand.
 */
#include "sendMessageStrat.h"

/**
 * @brief Handle a message by dispatching a SendMessageCommand.
 */
void SendMessageStrat::handleMessage(string message,Users* fromUsers,ChatRoom* room){
    SendMessageCommand sendstrat(room,message,fromUsers);
    sendstrat.execute();
}