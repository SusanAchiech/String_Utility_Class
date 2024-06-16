#pragma once
#include "Item.h"
#include <iostream>

class Cat : public Item {
public:
    Cat() : purring(false) {}
    ~Cat() {}

    void Use() override {
        if (purring) {
            std::cout << "You stop petting the cat." << std::endl;
            purring = false;
        }
        else {
            std::cout << "You start petting the cat and it purrs." << std::endl;
            purring = true;
        }
    }

    void Description() override {
        std::string desc = "A white spotted cat";
        if (purring) {
            desc += " that is purring";
        }
        else {
            desc += " that is not purring";
        }
        std::cout << desc << std::endl;
    }

    std::string description() const override {
        return "white spotted cat";
    }

private:
    bool purring;
};
