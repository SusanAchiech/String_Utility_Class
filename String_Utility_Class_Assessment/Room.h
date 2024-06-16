#pragma once
#include "Item.h"
#include "String.h"
#include <iostream>

class Room {
public:
    Room(const String& roomDescription, Item* item = nullptr);
    ~Room();

    void Description();
    Item* getItem() const;

private:
    String roomDescription;
    Item* item;
};
