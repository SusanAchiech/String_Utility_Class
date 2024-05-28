#pragma once
#include "Item.h"
#include <iostream>

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
			std::cout << "The box is empty.\n";
		}
	}
	void Use() override
	{	//checking the if the remaining number of dunots have been eaten
		if (donuts > 0)
		{
			donuts--;
			std::cout << "The remaining " << donuts << " donuts have been eaten.\n";
		}
		else
		{
			std::cout << "You cannot eat what you do not have!\n";
		}
	}
private:
	int donuts;
};
