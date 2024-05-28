#pragma once
#include <vector>
#include "String.h"
#include <iostream>
class Player
{
public:
	Player()
	{
		//creating  an array of spell names
		spells = { "Eclipse", "Frostbite", "Levitate", "Mirage", "Petrify", "Teleport", "Thunderwave", "Vortext" };
	}
	~Player();
	//performing a binary function to check the spells
	bool FindSpell(String spellName)
	{
		auto it = std::lower_bound(spells.begin(), spells.end(), spell);

		//checking if the player knows the spell
		if (it != spells.end() && *it == spell)
		{
			std::cout << "'You know the spell '" << spell.getString() << std::endl;
			return true;
		}
		else
		{
			std::cout << "'You do not know the spell '" << spell.getString() << std::endl;
			return false;
		}
	}

private:
	std::vector<String> spells;
};

