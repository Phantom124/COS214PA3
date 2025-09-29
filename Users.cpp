#include "Users.h"


Users::Users(string name,ChatRoom* room){
    this->name = name ;
    if(room != NULL){
        chatRooms.push_back(room);
    }
}
string Users::getName(){
    return this->name;
}