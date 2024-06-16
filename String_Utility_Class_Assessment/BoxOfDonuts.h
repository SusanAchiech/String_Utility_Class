#pragma once
#include "Item.h"
#include <iostream>

class BoxOfDonuts : public Item {
public:
    BoxOfDonuts();
    ~BoxOfDonuts();
    void Use() override;
    void Description() override;
    std::string description() const override;

private:
    int donuts;
};
