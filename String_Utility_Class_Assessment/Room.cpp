#include "Room.h"
#include <iostream>

// Constructor definition
Room::Room(const String& description, Item* item)
    : description(description), item(item) {}

// Destructor definition
Room::~Room() {
    delete item;
}

// Description method definition
void Room::Description() {
    std::cout << description << std::endl;
    // Checking the description of the item in the room
    if (item) {
        std::cout << "You see a " << item->Description() << " here." << std::endl;
    }
}

// GetItem method definition
Item* Room::GetItem() const {
    return item;
}
