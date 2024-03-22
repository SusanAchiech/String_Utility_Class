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
	//converting all characters in the string to lowercase
	String& ToLower()
	{
		for (size_t i = 0; i < s_length; i++)
		{
			s_data[i] = std::tolower(s_data[i]);
		}
		return *this;
	}

	//converting all characters in the string to uppercase
	String& ToUpper()
	{
		{
			for (size_t i = 0; i < s_length; i++)
			{
				s_data[i] = std::toupper(s_data[i]);
			}
			return *this;
		}
	}

	//searching for the first occurence of the string
	size_t Find(const String& str) 
		{

		char* found = std::strstr(s_data, str.s_data);
		//returning the index position if found
		if (found) 
		{
			return found - s_data;
		}
		//if not found
		return -1;
	}


	//searching for the first occurence of str within the string object

	size_t Find(size_t startIndex, const String& str) 
	{
		if (startIndex >= s_length) 
		{
			return -1;
		}
		char* found = std::strstr(s_data + startIndex, str.s_data);
		//returning the index of the starting position
		if (found) 
		{
			return found - s_data;
		}
		//if not found
		return -1;
	}

	String& Replace(const String& find, const String& replace)
	{
		size_t pos = 0;
		//creating a new string
		String result;

		while (pos < s_length) 
		{
			size_t foundPos = Find(pos, find);

			if (foundPos == -1) 
			{
				result.Append(*this, pos, s_length - pos);
				break;
			}
			//appending the r5elace string and updating the position
			result.Append(*this, pos, foundPos - pos);
			
			result.Append(replace);

			pos = foundPos + find.s_length;
		}
		*this = result;

		return *this;
	}

	String& ReadFromConsole()
	{
		//reading to line 1023
		char buffer[1024];

		std::cin.getline(buffer, 1024);
		//storing input in a temporary buffer 
		*this = String(buffer);

		return *this;

	}

	String& WriteToConsole() 
	{
		//allowing input into the console
		std::cout << m_data << std::endl;

		return *this;
	}
public:
	//comparing the current string with the other string
	bool operator==(const String& other) 
	
	{
		return EqualTo(other);
	}

	//returning the opposite of EqualTo()
	bool operator!=(const String& other) 
	{
		return !EqualTo(other);
	}

	String& operator=(const String& str)
	{
		//checking if this and str are not the same object
		if (this != &str) 
		{
			//if not then dellocating s_data
			delete[] s_data;
			//updating s_length  with str length
			s_length = str.s_length;
			s_data = new char[s_length + 1];
			//coping string data cfrom str.s_data to m_data
			std::strcpy(s_data, str.s_data);
		}
		return *this;
	}

	//returning const reference to the character
	char& operator[](size_t index)
	{
		return CharacterAt(index);
	}

	const char& operator[](size_t index) const
	{
		return CharacterAt(index);
	}

private:
	/*
	* Put your internal data structures and members here
	*/
};

#endif