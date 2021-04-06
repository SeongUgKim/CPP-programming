#include <cmath>
#include <cassert>
#include "EquilateralTriangleLawn.h"
using namespace std;
namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side)
		: Lawn()
		, mSide(side)
	{
		mCircumstance = 3 * mSide;
		mArea = static_cast<unsigned int>((sqrt(3.0) / 4.0) * pow(mSide, 2.0) + 0.5);
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return mArea;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned int minimumFencesCount = 0;
		minimumFencesCount = static_cast<unsigned int>(mCircumstance / 0.25);
		if (mCircumstance / 0.25 == static_cast<double>(minimumFencesCount))
		{
			return minimumFencesCount;
		}
		return minimumFencesCount + 1;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int price = 0;
		switch (fenceType)
		{
		case RED_CEDAR:
			price = mCircumstance * 6;
			break;
		case SPRUCE:
			price = mCircumstance * 7;
			break;
		default:
			assert(false);
			break;
		}
		return price;
	}

}