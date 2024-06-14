#pragma once
#include "Item.h"
#include <iostream>

class BoxOfDonuts : public Item
{
public:
    BoxOfDonuts();
    ~BoxOfDonuts();
    void Description() override;
    void Use() override;

private:
    int donuts;
};
