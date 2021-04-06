#pragma once
#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class EquilateralTriangleLawn : public IFenceable, public Lawn
	{
	public:
		EquilateralTriangleLawn(unsigned int side);
		virtual ~EquilateralTriangleLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mSide;
	};
}