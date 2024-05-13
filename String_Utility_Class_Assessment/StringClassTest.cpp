#include "StringClassTest.h"
#include <iostream>

StringClassTest::StringClassTest()
{

}

StringClassTest::~StringClassTest()
{

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
	
	PrintResult(message, str1, "Hello Susan!");
	
	//prepend test
	message = "Prepend Test";
	str1 = "Hello";
	str1.Prepend("Hello ");
	PrintResult(message, str1, "Hello Susan!");

	//Replace test
	message = "Replace Test";
	str1 = "Hello my name is Susan and I am 24 years old";
	str1.Replace("Susan", " 24");
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
	PrintResult(message, str1, "Welcome to Turkana");

	//ToLower test

	message = "ToLower Test";
	str1 = "WELCOME TO TURKANA";
	str1.ToLower();
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
		std::cout << "Got: " <<  result << std::endl;
		results.push_back(false);
	}
}

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