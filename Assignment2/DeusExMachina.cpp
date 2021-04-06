#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = NULL;
	DeusExMachina::DeusExMachina()
		: mSize(0)
	{
		for (int i = 0; i < MAX; ++i)
		{
			mArray[i] = NULL;
		}
	}
	DeusExMachina::~DeusExMachina()
	{
		for (int i = 0; i < MAX; ++i)
		{
			delete mArray[i];
			mArray[i] = NULL;
		}
	}
	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == NULL)
		{
			mInstance = new DeusExMachina();
			return mInstance;
		}
		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize == MAX)
		{
			return false;
		}
		vehicle->InitializeDistance();
		mArray[mSize++] = vehicle;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}
		delete mArray[i];
		for (; i < MAX - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}
		if (i == MAX - 1)
		{
			mArray[i] = NULL;
		}
		mSize--;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0)
		{
			return NULL;
		}
		Vehicle* ret = mArray[0];
		for (unsigned int i = 1; i < mSize; ++i)
		{
			ret = mArray[i]->GetDistance() > ret->GetDistance() ? mArray[i] : ret;
		}
		return ret;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		if (i >= mSize)
		{
			return NULL;
		}
		return mArray[i];
	}
}