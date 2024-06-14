#include "BoxOfDonuts.h"

// Constructor definition
BoxOfDonuts::BoxOfDonuts() : donuts(12) {}

// Destructor definition
BoxOfDonuts::~BoxOfDonuts() {}

// Description method definition
void BoxOfDonuts::Description()
{
    // Checking the number of donuts left
    if (donuts > 0)
    {
        std::cout << "This box of donuts has " << donuts << " left.\n";
    }
    else
    {
        std::cout << "The box is empty.\n";
    }
}

// Use method definition
void BoxOfDonuts::Use()
{
    // Checking if the remaining number of donuts have been eaten
    if (donuts > 0)
    {
        donuts--;
        std::cout << "The remaining " << donuts << " donuts have been eaten.\n";
    }
    else
    {
        std::cout << "You cannot eat what you do not have!\n";
    }
}
