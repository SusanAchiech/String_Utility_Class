#pragma once
#include "String.h"

class Spell
{
public:
	Spell();
	~Spell()
	void Cast();
	bool Compare(Spell& a, Spell& b) const;

private:
	String name;
	int damage;
};