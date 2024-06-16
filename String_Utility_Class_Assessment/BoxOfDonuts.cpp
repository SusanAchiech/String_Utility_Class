#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts() : donuts(12) {}

BoxOfDonuts::~BoxOfDonuts() {}

void BoxOfDonuts::Use() {
    if (donuts > 0) {
        donuts--;
        std::cout << "You eat a donut. " << donuts << " donuts left.\n";
    }
    else {
        std::cout << "The box is empty.\n";
    }
}

void BoxOfDonuts::Description() {
    if (donuts > 0) {
        std::cout << "This box of donuts has " << donuts << " left.\n";
    }
    else {
        std::cout << "The box is empty.\n";
    }
}

std::string BoxOfDonuts::description() const {
    return "box of donuts";
}