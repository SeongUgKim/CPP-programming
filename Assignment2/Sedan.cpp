#include <cassert>
#include "Sedan.h"
namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
		mTrailer = NULL;
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
		, mTrailer(NULL)
	{
		if (other.mTrailer != NULL)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (mTrailer != NULL)
		{
			delete mTrailer;
			mTrailer = NULL;
		}
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (mArray[i] != NULL)
			{
				assert(mArray[i] != NULL);
				delete mArray[i];
				mArray[i] = NULL;
			}
		}
		delete[] mArray;
		mArray = NULL;
		mCapacity = rhs.mCapacity;
		mSize = rhs.mSize;
		mRun = rhs.mRun;
		mBreak = rhs.mBreak;
		mDistance = rhs.mDistance;
		mArray = new const Person * [mCapacity];
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			if (rhs.mArray[i] == NULL)
			{
				mArray[i] = NULL;
				continue;
			}
			const Person* person = new const Person(rhs.mArray[i]->GetName().c_str(), rhs.mArray[i]->GetWeight());
			mArray[i] = person;
		}
		if (rhs.mTrailer != NULL)
		{
			mTrailer = new Trailer(rhs.mTrailer->GetWeight());
		}
		return *this;
	}

	Sedan::~Sedan()
	{
		if (mTrailer != NULL)
		{
			delete mTrailer;
			mTrailer = NULL;
		}
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		int totalWeight = getTotalWeight();
		if (mTrailer != NULL)
		{
			totalWeight += mTrailer->GetWeight();
		}
		if (totalWeight > 350)
		{
			return 300;
		}
		if (totalWeight > 260)
		{
			return 380;
		}
		if (totalWeight > 160)
		{
			return 400;
		}
		if (totalWeight > 80)
		{
			return 458;
		}
		return 480;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == NULL)
		{
			return false;
		}
		if (mTrailer != NULL)
		{
			return false;
		}
		mTrailer = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == NULL)
		{
			return false;
		}
		delete mTrailer;
		mTrailer = NULL;
		return true;
	}

	void Sedan::Move()
	{
		if (mTrailer == NULL)
		{
			if (mRun < 5)
			{
				mRun++;
				mBreak = 0;
				mDistance += GetMaxSpeed();
				return;
			}
			if (mRun == 5)
			{
				mBreak++;
				if (mBreak == 1)
				{
					mRun = 0;
				}
				return;
			}
		}
		if (mRun < 5)
		{
			mRun++;
			mBreak = 0;
			mDistance += GetMaxSpeed();
			return;
		}
		if (mRun == 5)
		{
			mBreak++;
			if (mBreak == 2)
			{
				mRun = 0;
			}
		}
	}
}