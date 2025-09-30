/**
 * @file Users.cpp
 * @brief Base user entity shared by concrete user types.
 */
#include "Users.h"


/**
 * @brief Construct a user with a name and optional initial room membership.
 * @param name Display name of the user.
 * @param room Optional room to immediately join; ignored if nullptr.
 */
Users::Users(string name,ChatRoom* room){
    this->name = name ;
    if(room != NULL){
        chatRooms.push_back(room);
    }
}
/**
 * @brief Get the user's display name.
 * @return string Name of the user.
 */
string Users::getName(){
    return this->name;
}