#include "sendMessageStrat.h"

void SendMessageStrat::handleMessage(string message,Users* fromUsers,ChatRoom* room){
    SendMessageCommand sendstrat(room,message,fromUsers);
    sendstrat.execute();
}