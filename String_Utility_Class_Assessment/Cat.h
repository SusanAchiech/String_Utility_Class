#pragma once
#include "Item.h"
#include <iostream>

class Cat : public Item
{
public:
    Cat();
    ~Cat();
    void Use();
    void Description();

private:
    bool purring;
};
