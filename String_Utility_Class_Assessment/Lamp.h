#pragma once
#include "Item.h"
class Lamp: public Item
{
public: 
	Lamp();
	~Lamp();
	void Use() override;
	void Description() override;

private:
	bool isOn;
};

