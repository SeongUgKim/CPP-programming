#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicle(unsigned int i) const;
		~DeusExMachina();
	private:
		enum { MAX = 10 };
		static DeusExMachina* mInstance;
		Vehicle* mArray[MAX];
		unsigned int mSize;
		DeusExMachina();
	};
}