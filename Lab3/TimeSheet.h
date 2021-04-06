#pragma once
#include <string>

using namespace std;

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		~TimeSheet();
		TimeSheet(const TimeSheet& other);
		TimeSheet& operator=(const TimeSheet& other);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const string& GetName() const;

	private:
		string mName;
		char* mTemp;
		size_t mLength;
		int* mEntry;
		size_t mEntryCapacity;
		size_t mEntryLength;
	};
}