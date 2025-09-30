#ifndef STRATEGY_H
#define STRATEGY_H

class Users;
class ChatRoom;
#include <string>
using namespace std;

class strategy
{
    public:
        virtual void handleMessage(string message,Users* fromUsers,ChatRoom* room)=0;
};
#endif //STRATEGY