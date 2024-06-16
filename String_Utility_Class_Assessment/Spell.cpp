#include "Spell.h"

// Constructor definition
Spell::Spell() : name(""), damage(0) {}

// Destructor definition
Spell::~Spell() {}

// Cast method definition
void Spell::Cast() const {
    std::cout << "You cast " << name.getString() << " dealing " << damage << " damage!" << std::endl;
}

// Compare method definition
bool Spell::Compare(const Spell& a, const Spell& b) const {
    return a.name < b.name;
}
