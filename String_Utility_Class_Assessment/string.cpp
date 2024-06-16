#pragma once
#include <string>

class String {
public:
    String() : value("") {}
    String(const std::string& val) : value(val) {}

    const std::string& getString() const {
        return value;
    }

    // Overload the < operator for comparison
    bool operator<(const String& other) const {
        return value < other.value;
    }

    // Optionally, overload the == operator for equality comparison
    bool operator==(const String& other) const {
        return value == other.value;
    }

private:
    std::string value;
};
