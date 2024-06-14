#pragma once
#include "Item.h"
#include <iostream>

class Lamp : public Item
{
public:
    Lamp();
    ~Lamp();
    void Use() override;
    void Description() override;

private:
    bool isOn;
};
