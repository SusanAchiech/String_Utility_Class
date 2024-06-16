#pragma once
#include "Item.h"
#include "String.h"
#include <iostream>

class Room : public Item {
public:
    Room(const String& description, Item* item = nullptr)
        : description(description), item(item) {}

    ~Room() {}

    void Room::Description() {
        std::cout << roomDescription << std::endl;
        // Checking the description of the item in the room
        if (item) {
            std::cout << "You see a " << item->description() << " here." << std::endl;
        }

    std::string description() const override {
        return description.getString();
    }

    Item* getItem() const {
        return item;
    }

private:
    String description;
    Item* item;
};
