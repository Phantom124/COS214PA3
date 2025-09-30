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


/**
 * @brief Program entry point.
 */
int main(){
    ChatRoom* room = new CrtlCat();
    Users* ede = new jerry("ede",room);
    Users* ad = new admin("admin",room);
    Command* command = new SendMessageCommand(room,"hi",ede);
    ede->addCommand(command);
    room->registerUser(ede);
    room->registerUser(ad);

    ede->send("Hi",room);

    delete ad;
    delete ede;
    delete room;

    return 0;
}