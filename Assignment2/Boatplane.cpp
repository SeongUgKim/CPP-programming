#include "Boatplane.h"
namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int totalWeight = getTotalWeight();
		double calculatedNum = 800 - (1.7 * totalWeight);
		if (calculatedNum < 0.0)
		{
			return 20;
		}
		unsigned int maxNum = static_cast<unsigned int>(calculatedNum + 0.5);
		return maxNum > 20 ? maxNum : 20;
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		int totalWeight = getTotalWeight();
		unsigned int res = static_cast<unsigned int>((150 * pow(EULER, ((500 - totalWeight) / static_cast<double>(300)))) + 0.5);
		return res;
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return max(GetSailSpeed(), GetFlySpeed());
	}

	void Boatplane::Move()
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
}