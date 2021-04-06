#include <cassert>
#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mCapacity(maxPassengersCount)
		, mSize(0)
		, mBreak(0)
		, mRun(0)
		, mDistance(0)
	{
		mArray = new const Person * [mCapacity];
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			mArray[i] = NULL;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mCapacity(other.mCapacity)
		, mSize(other.mSize)
		, mRun(other.mRun)
		, mBreak(other.mBreak)
		, mDistance(other.mDistance)
	{
		mArray = new const Person * [mCapacity];
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (other.mArray[i] == NULL)
			{
				mArray[i] = NULL;
				continue;
			}
			const Person* person = new const Person(other.mArray[i]->GetName().c_str(), other.mArray[i]->GetWeight());
			mArray[i] = person;
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (mArray[i] != NULL)
			{
				assert(mArray[i] != NULL);
				delete mArray[i];
				mArray[i] = NULL;
			}
		}
		delete[] mArray;
		mArray = NULL;
		mCapacity = rhs.mCapacity;
		mSize = rhs.mSize;
		mRun = rhs.mRun;
		mBreak = rhs.mBreak;
		mDistance = rhs.mDistance;
		mArray = new const Person * [mCapacity];
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (rhs.mArray[i] == NULL)
			{
				mArray[i] = NULL;
				continue;
			}
			const Person* person = new const Person(rhs.mArray[i]->GetName().c_str(), rhs.mArray[i]->GetWeight());
			mArray[i] = person;
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (mArray[i] == NULL)
			{
				continue;
			}
			delete mArray[i];
			mArray[i] = NULL;
		}
		delete[] mArray;
		mArray = NULL;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize == mCapacity)
		{
			return false;
		}
		mArray[mSize++] = person;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}
		delete mArray[i];
		for (; i < mCapacity - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}
		if (i == mCapacity - 1)
		{
			mArray[i] = NULL;
		}
		mSize--;
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mSize;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mCapacity;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mSize)
		{
			return NULL;
		}
		return mArray[i];
	}

	unsigned int Vehicle::GetDistance() const
	{
		return mDistance;
	}

	void Vehicle::InitializeDistance()
	{
		mDistance = 0;
	}
	int Vehicle::getTotalWeight() const
	{
		int totalWeight = 0;
		for (unsigned int i = 0; i < mSize; ++i)
		{
			totalWeight += static_cast<int>(mArray[i]->GetWeight());
		}
		return totalWeight;
	}
}