#include "UBoat.h"
namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		int totalWeight = getTotalWeight();
		double weight = static_cast<double>(totalWeight);
		double calculatedNum = 500 * log((weight + 150) / 150) + 30;
		unsigned int res = static_cast<unsigned int>(calculatedNum + 0.5);
		return res;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		int totalWeight = getTotalWeight();
		double weight = static_cast<double>(totalWeight);
		double calculatedNum = 550 - weight / 10;
		double maxNum = calculatedNum > 200 ? calculatedNum : 200;
		unsigned int res = static_cast<unsigned int>(maxNum + 0.5);
		return res;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return max(GetDiveSpeed(), GetSailSpeed());
	}

	void UBoat::Move()
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
			if (mBreak == 4)
			{
				mRun = 0;
			}
		}
	}
}