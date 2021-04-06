#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: Lawn()
		, mRadius(radius)
	{
		mArea = static_cast<unsigned int>(3.14 * mRadius * mRadius + 0.5);
		mCircumstance = static_cast<unsigned int>(2 * 3.14 * mRadius + 0.5);
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return mArea;
	}
}