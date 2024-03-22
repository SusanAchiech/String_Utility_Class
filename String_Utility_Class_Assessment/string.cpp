#include <String.h>
#include <iostream>

#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
public:
	//initiatizing string and setting it to zero
	String() : s_data(new char[1] {'\0'}), s_length(0) {}

	//
	String(const char* _str) {
		s_length = std::strlen(str);
		s_data = new char[s_length + 1];
		//copying input string
		std::strcpy(s_data, str);
	}

	String(const String& other) {
		s_length = other.s_length;
		s_data = new char[s_length + 1];
		std::strcpy(s_data, other.s_data);
	}

	~String() {
		//dellocating memory used
		delete s_data;
	}

public:
	//returning the length of the string stored
	size_t Length() const {
		return s_length;
	}

	//returning index of character in string
	char& CharacterAt(size_t _index)
	{
		//checking if the index is out of bounds
		if (index >= 0 && index < s_length)
		{
			return s_data[index];
		}
		return s_data[0];
	}

	const char& CharacterAt(size_t _index) const
	{
		if (index >= 0 && index < s_length)
		{
			return s_data[index]
		}
		return s_data[0];
	}
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

public:
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	String& operator=(const String& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

private:
	/*
	* Put your internal data structures and members here
	*/
};

#endif