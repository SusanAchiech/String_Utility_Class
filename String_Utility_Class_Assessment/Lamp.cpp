#include "Lamp.h"

// Constructor definition
Lamp::Lamp() : isOn(false) {}

// Destructor definition
Lamp::~Lamp() {}

// Use method definition
void Lamp::Use() {
    if (isOn) {
        std::cout << "You turn off the lamp and there is darkness." << std::endl;
        isOn = false;
    }
    else {
        std::cout << "You turn on the lamp and there is light." << std::endl;
        isOn = true;
    }
}

// Description method definition
void Lamp::Description() {
    std::string desc = "A glass lamp";
    if (isOn) {
        desc += " that is turned on";
    }
    else {
        desc += " that is turned off";
    }
    std::cout << desc << std::endl;
}
