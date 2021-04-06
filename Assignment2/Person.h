#pragma once
#include <string>
using namespace std;
namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
	private:
		string mStringName;
		char* mName;
		unsigned int mWeight;
	};
}