#include "Room.h"
#include "Item.h"
#include <iostream>

Room::Room(const String& roomDescription, Item* item)
    : roomDescription(roomDescription), item(item) {}

Room::~Room() {}

void Room::Description() {
    std::cout << roomDescription.CStr() << std::endl;
    if (item) {
        std::cout << "You see a " << item->description() << " here." << std::endl;
    }
}
