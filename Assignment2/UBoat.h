#pragma once
#include "IDivable.h"
#include "ISailable.h"
#include "Vehicle.h"
namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		~UBoat();
		unsigned int GetDiveSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
		void Move();
	};
}