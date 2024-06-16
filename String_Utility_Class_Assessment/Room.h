#pragma once
#include "Item.h"
#include "String.h"
#include <iostream>

class Room {
public:
    // Initializing the item descriptions in the room
    Room(const String& roomDescription, Item* item = nullptr)
        : roomDescription(roomDescription), item(item) {}

    ~Room();

    void Description();

    Item* getItem() const {
        return item;
    }

private:
    String roomDescription; // Renamed to avoid conflict
    Item* item;
};
