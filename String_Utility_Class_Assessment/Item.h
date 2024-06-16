#pragma once
#include <string>

class Item {
public:
    Item();
    virtual ~Item() = default;
    virtual void Use() = 0;
    virtual void Description() = 0;
    virtual std::string description() const = 0;
};
