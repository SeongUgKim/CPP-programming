#include "Person.h"

namespace assignment2
{
	const unsigned int NULL_CHARACTER = 1;
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		unsigned int length = 0;
		length = strlen(name);
		mName = new char[length + NULL_CHARACTER];
		memcpy(mName, name, length + NULL_CHARACTER);
		mStringName = mName;
	}

	Person::~Person()
	{
		delete[] mName;
		mName = NULL;
	}

	const std::string& Person::GetName() const
	{
		return mStringName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}