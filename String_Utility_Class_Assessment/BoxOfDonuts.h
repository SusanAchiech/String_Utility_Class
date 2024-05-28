#pragma once
#include "Item.h"

class BoxOfDonuts : public Item
{
public:
	BoxOfDonuts();
	~BoxOfDonuts();
	void Description() override
	{
		//checking the number of donuts left
		if (donuts > 0)
		{
			std::cout << "This box of donuts has " << donuts << "left.\n";
		}
		else
		{
			std::cout << "The box is empty.\n",
		}
	}
	void Use() override
	{

	}
private:
	int donuts;
};
