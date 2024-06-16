#include "Spell.h"

Spell::Spell() : name(""), damage(0) {}

Spell::~Spell() {}

void Spell::Cast() const {
    std::cout << "You cast " << name.CStr() << " dealing " << damage << " damage!" << std::endl;
}

bool Spell::Compare(const Spell& a, const Spell& b) const {
    return a.name < b.name;
}
