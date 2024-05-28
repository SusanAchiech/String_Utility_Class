#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();
	~BoxOfDonuts();
	void Use() override;
	void Description() override;
private:
	int donuts;
};
