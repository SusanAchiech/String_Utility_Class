#pragma once
#include "Item.h"
#include <iostream>

class BoxOfDonuts : public Item {
public:
    BoxOfDonuts() : donuts(12) {} // Assuming a box starts with 12 donuts
    ~BoxOfDonuts() {}

    void Use() override {
        if (donuts > 0) {
            donuts--;
            std::cout << "You eat a donut. " << donuts << " donuts left.\n";
        }
        else {
            std::cout << "The box is empty.\n";
        }
    }

    void Description() override {
        if (donuts > 0) {
            std::cout << "This box of donuts has " << donuts << " left.\n";
        }
        else {
            std::cout << "The box is empty.\n";
        }
    }

    std::string description() const override {
        return "box of donuts";
    }

private:
    int donuts;
};
