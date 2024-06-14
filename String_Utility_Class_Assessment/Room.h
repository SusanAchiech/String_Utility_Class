#pragma once
#include "Item.h"
#include "String.h"
#include <iostream>

class Room : public Item
{
public:
    Room(const String& description, Item* item = nullptr);
    ~Room();
    void Description();
    Item* GetItem() const;

private:
    String description;
    Item* item;
};
