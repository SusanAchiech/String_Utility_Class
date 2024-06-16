#pragma once
#include "Item.h"
#include <iostream>

class Lamp : public Item {
public:
    Lamp() : isOn(false) {}
    ~Lamp() {}

    void Use() override {
        if (isOn) {
            std::cout << "You turn off the lamp and there is darkness." << std::endl;
            isOn = false;
        }
        else {
            std::cout << "You turn on the lamp and there is light." << std::endl;
            isOn = true;
        }
    }

    void Description() override {
        std::string desc = "A glass lamp";
        if (isOn) {
            desc += " that is turned on";
        }
        else {
            desc += " that is turned off";
        }
        std::cout << desc << std::endl;
    }

    std::string description() const override {
        return "glass lamp";
    }

private:
    bool isOn;
};
