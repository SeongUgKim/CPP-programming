#pragma once
#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& rhs);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual void Move() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetDistance() const;
		void InitializeDistance();
	protected:
		unsigned int mCapacity;
		unsigned int mSize;
		const Person** mArray;
		const double EULER = 2.7182818284590452353602874;
		int getTotalWeight() const;
		unsigned int mBreak;
		unsigned int mDistance;
		unsigned int mRun;
	};
}