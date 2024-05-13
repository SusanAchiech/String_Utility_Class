#include "StringClassTest.h"
#include <iostream>

StringClassTest::StringClassTest()
{

}

StringClassTest::~StringClassTest()
{

}

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
	str1.Append("World");
	
	PrintResult(message, str1, "Hello World!");
	
	//prepend test
	message = "Prepend Test";
	str1 = "Hello";
	str1.Prepend("Hello ");
	PrintResult(message, str1, "Hello World!");



}

void StringClassTest::PrintResult(String& message, String& result, const char* expected)
{
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