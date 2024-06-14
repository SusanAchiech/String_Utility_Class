#pragma once
#include <vector>
#include "String.h"
#include <iostream>
#include <algorithm>
#include "spell.h"

class Player
{
public:
    Player();
    ~Player();
    bool FindSpell(String spellName);

private:
    std::vector<String> spells;
};
