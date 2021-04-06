#include <cassert>
#include <iostream>
#include "MyString.h"

using namespace assignment1;
using namespace std;
int main()
{
	int beforeAddress1;
	int beforeAddress2;

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	beforeAddress1 = (int)testString1.GetCString();
	assert(testString1.IndexOf("Happy") == 0);
	assert(testString1.IndexOf("ppy") == 2);
	assert(testString1.IndexOf("") == 0);
	assert(beforeAddress1 == (int)testString1.GetCString());

	beforeAddress1 = (int)testString1.GetCString();
	assert(testString1.LastIndexOf("Happy") == 6);
	assert(testString1.LastIndexOf("ppy") == 8);
	assert(testString1.LastIndexOf("") == 16);
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "E5_NoMallocInIndexOf Åë°ú" << endl;



	return 0;

	
}

