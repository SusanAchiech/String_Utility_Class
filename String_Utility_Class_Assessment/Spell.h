#pragma once
#include "String.h"
#include <iostream>

class Spell
{
public:
	//initializing name as empty and damage to 0
	Spell(): name(""), damage(0){}
	~Spell()
		void Cast()
	{
		std::cout << "You cast " << name.getString() << " dealing" << damage << " damage!" << std::endl;
	}
	//comparing the two spell objects
	bool Compare(const Spell& a, const Spell& b) const
	{
		return a.name < b.name;
	}

private:
	String name;
	int damage;
};