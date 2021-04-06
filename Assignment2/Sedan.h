#pragma once
#include "IDrivable.h"
#include "Vehicle.h"
#include "Trailer.h"
namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& rhs);
		~Sedan();
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		void Move();
	private:
		const Trailer* mTrailer;
	};
}