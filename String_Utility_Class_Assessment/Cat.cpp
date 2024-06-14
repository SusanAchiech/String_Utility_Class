#include "cat.h"

// Constructor definition
Cat::Cat() : purring(false) {}

// Destructor definition
Cat::~Cat() {}

// Use method definition
void Cat::Use()
{
    if (purring)
    {
        std::cout << "You stop petting the cat." << std::endl;
        purring = false;
    }
    else
    {
        std::cout << "You start petting the cat and it purrs" << std::endl;
        purring = true;
    }
}

// Description method definition
void Cat::Description()
{
    std::string desc = "A white spotted cat";
    if (purring)
    {
        desc += " that is purring";
    }
    else
    {
        desc += " that is not purring";
    }
    std::cout << desc << std::endl;
}
