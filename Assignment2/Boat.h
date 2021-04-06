#pragma once
#include "Boatplane.h"
#include "ISailable.h"
#include "Vehicle.h"
namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
		Boatplane operator+(Airplane& plane);
		void Move();
	};
}