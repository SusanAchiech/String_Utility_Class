#pragma once
#include <vector>
#include "String.h"
class Player
{
public:
	Player();
	~Player();
	bool FindSpell(String spellName);

private:
	std::vector<String> spells;
};

