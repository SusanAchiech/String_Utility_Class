#pragma once
#include <cstring>
#include <iostream>

class String {
public:
    // Constructors and Destructor
    String();
    String(const char* _str);
    String(const String& other);
    ~String();

    // Member Functions
    size_t Length() const;
    char& CharacterAt(size_t _index);
    const char& CharacterAt(size_t _index) const;
    bool EqualTo(const String& _other) const;
    String& Append(const String& _str);
    String& Prepend(const String& _str);
    const char* CStr() const;
    String& ToLower();
    String& ToUpper();
    size_t Find(const String& _str);
    size_t Find(size_t _startIndex, const String& _str);
    String& Replace(const String& _find, const String& _replace);
    String& ReadFromConsole();
    String& WriteToConsole();

    // Operator Overloads
    bool operator==(const String& _other) const;
    bool operator!=(const String& _other) const;
    bool operator<(const String& _other) const; // Adding the less than operator
    String& operator=(const String& _str);
    char& operator[](size_t _index);
    const char& operator[](size_t _index) const;

    // Non-member Function
    friend std::ostream& operator<<(std::ostream& os, const String& str);

private:
    // Helper Functions
    String& Append(const String& str, size_t start, size_t count);

    char* s_data;
    size_t s_length;
};




