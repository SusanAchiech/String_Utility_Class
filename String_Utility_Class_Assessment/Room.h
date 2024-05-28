#pragma once
#include "Item.h"
#include "String.h"
class Room: public Item
{
public: 
	Room();
	~Room();
	void Description();
private: 
	Item* Item;
	String description;

};

