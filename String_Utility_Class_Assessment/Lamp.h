#pragma once
#include "Item.h"
#include <iostream>
class Lamp: public Item
{
public: 
	Lamp() : isOn(false)
	{
	}
		~Lamp();

	void Use()
	{
		if (isOn)
		{
			std::cout << "You turn on lamp and there is light." << std::endl;
		
		}
		else
		{
			std::cout << "You turn off lanp and there is darkness" << std::endl;
			
		}
	}
	void Description()

	{
		std::string desc = "A glass lamp";
		if (isOn)
		{
			desc += " that is turned on";
		}
		else
		{
			desc += " that is turned off";
		}
		std::cout << desc << std::endl;
	}

private:
	bool isOn;
};

