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

	//returning the index of the chtracter in the string 
	const char& CharacterAt(size_t _index) const
	{
		//checking if the index is valid
		if (index >= 0 && index < s_length)
		{
			return s_data[index]
		}
		//if out of bounds then return 0
		return s_data[0];
	}

	//comparing the two string objects
	bool EqualTo(const String& _other) const
	{
		return std::strcmp(s_data, other.s_data) == 0;
	}

	//appending the string data from str to current string
	String& Append(const String& str) {
		//creating a new character
		char* temp = new char[s_length + str.s_length + 1];
		//copying the current string data into temp
		std::strcpy(temp, s_data);
		//appending the str
		std::strcat(temp, str.s_data);
		//dellocating the old s_data
		delete[] s_data;
		//updating s_data to point to temp
		s_data = temp;
		//updating s_data to reflect new length
		s_length += str.s_length;
		//returning the modified string
		return *this;
	}
	String& Prepend(const String& _str)
	{
		//creating a new character
		char* temp = new char[m_length + str.m_length + 1];
		//copying the str data into temp
		std::strcpy(temp, str.m_data);
		//updating s_data to reflect new length
		std::strcat(temp, m_data);
		//creating a new character
		delete[] m_data;
		//updating s_data to reflect new length
		m_data = temp;
		//updating s_data to reflect new length
		m_length += str.m_length;
		//returning the modified string
		return *this;
	}

	const char* CStr() const {
		return m_data;
	}

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