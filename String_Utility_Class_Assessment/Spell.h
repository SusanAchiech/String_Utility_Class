#pragma once
#include "String.h"
#include <iostream>

class Spell {
public:
    Spell();
    ~Spell();
    void Cast() const;
    bool Compare(const Spell& a, const Spell& b) const;

private:
    String name;
    int damage;
};
