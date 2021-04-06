#include "Boat.h"
#include "Airplane.h"
#include "Boatplane.h"
namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int totalWeight = getTotalWeight();

		int calculatedNum = 800 - 10 * totalWeight;
		return calculatedNum > 20 ? calculatedNum : 20;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	void Boat::Move()
	{
		if (mRun == 0 || mRun == 1)
		{
			mBreak = 0;
			mRun++;
			mDistance += GetMaxSpeed();
			return;
		}
		if (mRun == 2)
		{
			mBreak++;
			if (mBreak == 1)
			{
				mRun = 0;
			}
		}
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int boatPassengerCount = mCapacity;
		unsigned int airplanePassengerCount = plane.GetMaxPassengersCount();
		unsigned int totalPassengerCount = boatPassengerCount + airplanePassengerCount;
		Boatplane bp(totalPassengerCount);
		while (plane.GetPassengersCount() > 0)
		{
			const Person* p = new const Person(plane.GetPassenger(0)->GetName().c_str(), plane.GetPassenger(0)->GetWeight());
			bp.AddPassenger(p);
			plane.RemovePassenger(0);
		}
		while (mSize > 0)
		{
			const Person* q = new const Person(mArray[0]->GetName().c_str(), mArray[0]->GetWeight());
			bp.AddPassenger(q);
			RemovePassenger(0);
		}
		return bp;
	}
}