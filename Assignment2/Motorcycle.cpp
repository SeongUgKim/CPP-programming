#include "Motorcycle.h"
namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		int totalWeight = getTotalWeight();
		double weight = static_cast<double>(totalWeight);
		double calculatedNum = ((-1) * pow((weight / 15), 3)) + 2 * weight + 400;
		double maxNum = calculatedNum > 0.0 ? calculatedNum : 0.0;
		unsigned int res = static_cast<unsigned int>(maxNum + 0.5);
		return res;
	}

	void Motorcycle::Move()
	{
		if (mRun < 5)
		{
			mRun++;
			mBreak = 0;
			mDistance += GetMaxSpeed();
			return;
		}
		if (mRun == 5)
		{
			mBreak++;
			if (mBreak == 1)
			{
				mRun = 0;
			}
		}
	}
}
