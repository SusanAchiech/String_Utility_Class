#include "string.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

String::String() : s_data(nullptr), s_length(0) {}

String::String(const char* _str) {
    s_length = strlen(_str);
    s_data = new char[s_length + 1];
    strcpy(s_data, _str);
}

String::String(const String& other) {
    s_length = other.s_length;
    s_data = new char[s_length + 1];
    strcpy(s_data, other.s_data);
}

String::~String() {
    delete[] s_data;
}

size_t String::Length() const {
    return s_length;
}

char& String::CharacterAt(size_t _index) {
    return s_data[_index];
}

const char& String::CharacterAt(size_t _index) const {
    return s_data[_index];
}

bool String::EqualTo(const String& _other) const {
    return strcmp(s_data, _other.s_data) == 0;
}

String& String::Append(const String& _str) {
    return Append(_str, 0, _str.Length());
}

String& String::Prepend(const String& _str) {
    String temp(*this);
    delete[] s_data;
    s_length = _str.s_length + temp.s_length;
    s_data = new char[s_length + 1];
    strcpy(s_data, _str.s_data);
    strcat(s_data, temp.s_data);
    return *this;
}

const char* String::CStr() const {
    return s_data;
}

String& String::ToLower() {
    for (size_t i = 0; i < s_length; ++i) {
        s_data[i] = tolower(s_data[i]);
    }
    return *this;
}

String& String::ToUpper() {
    for (size_t i = 0; i < s_length; ++i) {
        s_data[i] = toupper(s_data[i]);
    }
    return *this;
}

size_t String::Find(const String& _str) {
    char* pos = strstr(s_data, _str.s_data);
    return pos ? pos - s_data : -1;
}

size_t String::Find(size_t startIndex, const String& str) {
    char* pos = strstr(s_data + startIndex, str.s_data);
    return pos ? pos - s_data : -1;
}

String& String::Replace(const String& find, const String& replace) {
    size_t pos = Find(find);
    if (pos != -1) {
        size_t newLength = s_length - find.s_length + replace.s_length;
        char* newData = new char[newLength + 1];
        strncpy(newData, s_data, pos);
        strcpy(newData + pos, replace.s_data);
        strcpy(newData + pos + replace.s_length, s_data + pos + find.s_length);
        delete[] s_data;
        s_data = newData;
        s_length = newLength;
    }
    return *this;
}

String& String::ReadFromConsole() {
    std::string input;
    std::getline(std::cin, input);
    delete[] s_data;
    s_length = input.length();
    s_data = new char[s_length + 1];
    strcpy(s_data, input.c_str());
    return *this;
}

String& String::WriteToConsole() {
    std::cout << s_data;
    return *this;
}

bool String::operator==(const String& _other) const {
    return EqualTo(_other);
}

bool String::operator!=(const String& _other) const {
    return !EqualTo(_other);
}

bool String::operator<(const String& _other) const {
    return strcmp(s_data, _other.s_data) < 0;
}

String& String::operator=(const String& _str) {
    if (this != &_str) {
        delete[] s_data;
        s_length = _str.s_length;
        s_data = new char[s_length + 1];
        strcpy(s_data, _str.s_data);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.s_data;
    return os;
}

// Provide the implementation for the Append function that takes start and count arguments
String& String::Append(const String& str, size_t start, size_t count) {
    if (start >= str.s_length) {
        return *this;
    }

    size_t newLength = s_length + count;
    char* newData = new char[newLength + 1];
    strcpy(newData, s_data);
    strncat(newData, str.s_data + start, count);
    delete[] s_data;
    s_data = newData;
    s_length = newLength;
    return *this;
}