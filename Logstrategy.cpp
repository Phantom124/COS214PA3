#include "Logstrategy.h"

void logStrategy::handleMessage(string message,Users* fromUsers,ChatRoom* room){
    LogMessageCommand logStrategy(room,message,fromUsers);
    logStrategy.execute();
}