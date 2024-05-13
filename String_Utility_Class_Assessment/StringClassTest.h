#pragma once
#include "String.h"
#include  <vector>
class StringClassTest
{
public:
	StringClassTest();
	~StringClassTest();

	void Run();

private:
	void PrintTestHeader();
	void PrintResult(String& message, String& result, const char* expected);
	bool CheckString(String& str, const char* expected);
	void PrintPassFailRate();

	std::vector<bool> results;

};

bool StringClassTest::CheckString(String& str, const char* expected)
{
	return str == (String)expected;
}

