#pragma once
#include "Item.h"
#include "String.h"
#include <iostream>
class Room: public Item
{
public: 
	//initializing the item descriptions in the room
	Room(const String& description, Item* Item = nullptr)
		:description(description), Item(Item){}
	~Room();
	void Description()
	{
	std::cout << description << std::endl;
	//checking the description of the item in the room
		if (Item)
		{
			std::cout << "You see a " << Item->description() << " here." << std::endl;
		}
	}
	Item* Item;
private: 
	//returning the item pointer
	
	String description;

};

