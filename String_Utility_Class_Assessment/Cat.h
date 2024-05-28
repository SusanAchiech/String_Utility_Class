#pragma once
#include "Item.h"
class Cat: public Item
{
public:
	Cat();
	~Cat();

	void Use() override;
	void Description() override;

private:
	bool purring;
};

