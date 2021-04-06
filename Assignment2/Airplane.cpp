#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		return max(GetDriveSpeed(), GetFlySpeed());
	}
	unsigned int Airplane::GetFlySpeed() const
	{
		int totalWeight = getTotalWeight();
		unsigned int res = static_cast<unsigned int>((200 * pow(EULER, (-1 * totalWeight + 800) / static_cast<double>(500))) + 0.5);
		return res;
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		int totalWeight = getTotalWeight();
		unsigned int res = static_cast<unsigned int>((4 * pow(EULER, (-1 * totalWeight + 400) / static_cast<double>(70))) + 0.5);
		return res;
	}
	void Airplane::Move()
	{
		if (mRun == 0)
		{
			mBreak = 0;
			mRun++;
			mDistance += GetMaxSpeed();
			return;
		}
		if (mRun == 1)
		{
			mBreak++;
			if (mBreak == 3)
			{
				mRun = 0;
			}
		}
	}
	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int airplanePassengerCount = mCapacity;
		unsigned int boatPassengerCount = boat.GetMaxPassengersCount();
		unsigned int totalPassengerCount = airplanePassengerCount + boatPassengerCount;
		Boatplane bp(totalPassengerCount);
		while (mSize > 0)
		{
			const Person* p = new const Person(mArray[0]->GetName().c_str(), mArray[0]->GetWeight());
			bp.AddPassenger(p);
			RemovePassenger(0);
		}
		while (boat.GetPassengersCount() > 0)
		{
			const Person* q = new const Person(boat.GetPassenger(0)->GetName().c_str(), boat.GetPassenger(0)->GetWeight());
			bp.AddPassenger(q);
			boat.RemovePassenger(0);
		}
		return bp;
	}
}