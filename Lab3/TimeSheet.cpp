#include <cassert>
#include "TimeSheet.h"

namespace lab3
{
	const int MIN_HOUR = 1;
	const int MAX_HOUR = 10;
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mEntryCapacity(maxEntries)
		, mEntryLength(0)
	{
		size_t length = 0;
		const char* p = name;
		while (*p++ != '\0')
		{
			length++;
		}
		mLength = length;
		mTemp = new char[mLength + 1];
		strcpy(mTemp, name);
		mName = mTemp;
		mEntry = new int[mEntryCapacity];
		memset(mEntry, INT_MIN, sizeof(int) * mEntryCapacity);
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTemp;
		mTemp = NULL;
		delete[] mEntry;
		mEntry = NULL;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mEntryCapacity(other.mEntryCapacity)
		, mEntryLength(other.mEntryLength)
		, mLength(other.mLength)
	{
		mTemp = new char[mLength + 1];
		strcpy(mTemp, other.mTemp);
		mName = mTemp;
		mEntry = new int[mEntryCapacity];
		memcpy(mEntry, other.mEntry, sizeof(int) * mEntryCapacity);
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (mTemp != NULL)
		{
			delete[] mTemp;
		}
		mTemp = NULL;
		if (mEntry != NULL)
		{
			delete[] mEntry;
		}
		mEntry = NULL;
		mLength = rhs.mLength;
		mTemp = new char[mLength + 1];
		strcpy(mTemp, rhs.mTemp);
		mName = mTemp;
		mEntryLength = rhs.mEntryLength;
		mEntryCapacity = rhs.mEntryCapacity;
		mEntry = new int[mEntryCapacity];
		memcpy(mEntry, rhs.mEntry, sizeof(int) * mEntryCapacity);
		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < MIN_HOUR || timeInHours > MAX_HOUR)
		{
			return;
		}
		if (mEntryLength == mEntryCapacity)
		{
			return;
		}
		mEntry[mEntryLength++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mEntryLength)
		{
			return -1;
		}
		return mEntry[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		size_t i = 0;
		int total = 0;
		for (; i < mEntryLength; ++i)
		{
			total += mEntry[i];
		}
		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		float dayCount = static_cast<float>(mEntryLength);
		float total = static_cast<float>(GetTotalTime());
		if (dayCount == 0.0f || total == 0.0f)
		{
			return 0.0f;
		}
		assert(dayCount != 0.0f && total != 0.0f);
		float averageTime = total / dayCount;
		return averageTime;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mEntryLength == 0)
		{
			return 0.0f;
		}
		float mean = GetAverageTime();
		float total = 0.0f;
		for (size_t i = 0; i < mEntryLength; ++i)
		{
			float diff = mEntry[i] - mean;
			total += static_cast<float>(pow(diff, 2.0f));
		}
		if (total == 0.0f)
		{
			return 0.0f;
		}
		float variance = total / static_cast<float>(mEntryLength);
		float sd = static_cast<float>(sqrt(variance));
		return sd;
	}

	const string& TimeSheet::GetName() const
	{
		return mName;
	}
}