#pragma once
class Item
{
public:
	virtual ~Item() = default;
	virtual void Description() = 0;
	virtual void Use() = 0;
};

