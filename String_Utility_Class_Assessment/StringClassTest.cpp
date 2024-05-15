#include "StringClassTest.h"
#include <iostream>

StringClassTest::StringClassTest()
{

}

StringClassTest::~StringClassTest()
{

}


bool StringClassTest::CheckString(String& str, const char* expected)
{
	return str == (String)expected;
}

//print date and time to the console
void StringClassTest::PrintTestHeader()
{
	std::cout << "String Test\n"
		<< "-----------\n"
		<< "Date: " << __DATE__
		<< " Time: " << __TIME__ << std::endl << std::endl;
}

void StringClassTest::Run()
{
	PrintTestHeader();

	//append test
	String message = "Append Test";
	String str1 = "Hello";
	str1.Append("Susan");
	
	PrintResult(message, str1, "HelloSusan");
	
	//prepend test
	message = "Prepend Test";
	str1 = "Hello";
	str1.Prepend("Hello ");
	PrintResult(message, str1, "Hello Hello");

	//Replace test
	message = "Replace Test";
	str1 = "Hello my name is Susan and I am 24 years old";
	str1.Replace("Susan", "Paul");
	str1.Replace("24", "26");
	PrintResult(message, str1, "Hello my name is Paul and I am 26 years old");

	//Find test
	message = "Find Test";
	str1 = "Hello Susan";
	str1.Find("Susan");
	PrintResult(message, str1, "Hello Susan");

	//ToUper test
	message = "ToUpper Test";
	str1 = "Welcome to Turkana";
	str1.ToUpper();
	PrintResult(message, str1, "WELCOME TO TURKANA");

	//ToLower test
	message = "ToLower Test";
	str1 = "WELCOME TO TURKANA";
	str1.ToLower();
	PrintResult(message, str1, "welcome to turkana");

	//EqualTo test
	message = "EqualTo Test";
	str1 = "Welcome to Turkana";
	str1.EqualTo("WELCOME TO TURKANA");
	PrintResult(message, str1, "Welcome to Turkana");

	// CharacterAt test
	message = "CharacterAt Test";
	str1 = "Welcome to Turkana";
	char expectedChar = 'o';
	char actualChar = str1.CharacterAt(4);
	PrintResult(message, str1, "Welcome to Turkana");


}

void StringClassTest::PrintResult(String& message, String& result, const char* expected)
{
	//writing to console test
	message.WriteToConsole();
	if (CheckString(result, expected))
	{
		std::cout << " PASSED" << std::endl;
		results.push_back(true);
	}
	else
	{
		std::cout << " FAILED" << std::endl;
		std::cout << "Expected: " << expected << std::endl;
		std::cout << "Got: " <<  result.CStr() << std::endl;
		results.push_back(false);
	}
}

//checking for the status percentage of the project
void StringClassTest::PrintPassFailRate()
{
	int passed = 0;
	for (int i = 0; i < results.size(); i++)
	{
		if (results[i])
		{
			passed++;
		}
	}
	std::cout << "\nPassed: " << passed
		<< " Failed: " << results.size() - passed
		<< " Failed Rate: " << (results.size() - passed) / (float)results.size() * 100 << "%\n";
}