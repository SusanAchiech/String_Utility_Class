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
	void SaveToFile(String& ouutputText);

	std::vector<bool> results;

};


