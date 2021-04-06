#include <cassert>
#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
		: mArea(0)
		, mCircumstance(0)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int grassPrice = 0;
		switch (grassType)
		{
		case BERMUDA:
			grassPrice = 8 * mArea;
			break;
		case BAHIA:
			grassPrice = 5 * mArea;
			break;
		case BENTGRASS:
			grassPrice = 3 * mArea;
			break;
		case PERENNIAL_RYEGRASS:
			grassPrice = static_cast<unsigned int>(2.5 * mArea);
			if (2.5 * mArea != static_cast<double>(grassPrice))
			{
				grassPrice++;
			}
			break;
		case ST_AUGUSTINE:
			grassPrice = static_cast<unsigned int>(4.5 * mArea);
			if (4.5 * mArea != static_cast<double>(grassPrice))
			{
				grassPrice++;
			}
			break;
		default:
			assert(false);
			break;
		}
		return grassPrice;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int minimumSodRollCount = 0;
		minimumSodRollCount = static_cast<unsigned int>(mArea / 0.3);
		if (mArea / 0.3 == static_cast<double>(minimumSodRollCount))
		{
			return minimumSodRollCount;
		}
		return minimumSodRollCount + 1;
	}
}