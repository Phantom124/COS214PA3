/**
 * @file main.cpp
 * @brief Simple demonstration of the chat system wiring commands, users, and rooms.
 */
#include "Chatroom.h"
#include "admin.h"
#include "Command.h"
#include "Users.h"
#include "jerry.h" 
#include "admin.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "CrtlCat.h"
#include "UserIterator.h"
#include "UserVector.h"
#include "MessageIterator.h"
#include "MessageVector.h"


/**
 * @brief Program entry point.
 */
int main(){
    ChatRoom* room = new CrtlCat();
    Users* ede = new jerry("ede",room);
    Users* ad = new admin("admin",room);
    Command* command = new SendMessageCommand(room,"hi",ede);

    cout << "Here \n";

    ede->addCommand(command);

    cout << "Here after adding command\n";

    room->registerUser(ede);

    cout << "Here after adding registered user\n";

    room->registerUser(ad);

    cout << "Here after adding registered another user\n";

    ede->send("Hi",room);

    cout << "Here after adding command\n";

    delete ad;
    delete ede;
    delete room;

    return 0;
}