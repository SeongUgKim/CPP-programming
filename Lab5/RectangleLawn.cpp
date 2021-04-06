#include <cassert>
#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: Lawn()
		, mWidth(width)
		, mHeight(height)
	{
		mArea = mWidth * mHeight;
		mCircumstance = 2 * (mWidth + mHeight);
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mArea;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int minimumFencesCount = static_cast<unsigned int>(mCircumstance / 0.25);
		if (mCircumstance / 0.25 == static_cast<double>(minimumFencesCount))
		{
			return minimumFencesCount;
		}
		return minimumFencesCount + 1;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencePrice = 0;
		switch (fenceType)
		{
		case RED_CEDAR:
			fencePrice = mCircumstance * 6;
			break;
		case SPRUCE:
			fencePrice = mCircumstance * 7;
			break;
		default:
			assert(false);
			break;
		}
		return fencePrice;
	}
}