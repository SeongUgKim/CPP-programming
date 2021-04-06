#pragma once
#include <cstddef>
#include <cassert>
#include "FixedVector.h"
using namespace std;
namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector() = default;
		FixedVector(const FixedVector& other) = default;
		FixedVector<bool, N>& operator=(const FixedVector& rhs) = default;
		bool Add(const bool bT);
		bool Remove(const bool bT);
		bool Get(size_t index) const;
		bool operator[](size_t index) const;
		int GetIndex(const bool bT) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		void removeBit(size_t currentArrIndex, size_t removalIndex);
		enum
		{
			MAX = (N % 32 != 0) ? N / 32 + 1 : N / 32
		};
		size_t mSize;
		size_t mArray[MAX];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		memset(mArray, 0, MAX);
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool bT)
	{
		if (mSize >= N)
		{
			return false;
		}
		size_t arrIndex = mSize / 32;
		size_t arrBit = mSize % 32;
		if (bT == true)
		{
			mArray[arrIndex] |= (1 << arrBit);
		}
		else
		{
			mArray[arrIndex] &= ~(1 << arrBit);
		}
		mSize++;
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool bT)
	{
		if (mSize == 0)
		{
			return false;
		}
		size_t arrSize = (mSize % 32 != 0) ? (mSize / 32 + 1) : (mSize / 32);
		size_t i = 0;
		for (; i < arrSize - 1; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (((mArray[i] >> j) & 1) == bT)
				{
					removeBit(i, j);
					for (size_t k = i + 1; k < arrSize; ++k)
					{
						if ((mArray[k] & 1) == 1)
						{
							mArray[k - 1] |= (1 << 31);
						}
						else
						{
							mArray[k - 1] &= ~(1 << 31);
						}
						mArray[k] >>= 1;
					}
					mSize--;
					return true;
				}
			}
		}
		int bitLength = (mSize % 32 != 0) ? mSize % 32 : 32;
		for (int j = 0; j < bitLength; ++j)
		{
			if (((mArray[i] >> j) & 1) == bT)
			{
				removeBit(i, j);
				for (size_t k = i + 1; k < arrSize; ++k)
				{
					if ((mArray[k] & 1) == 1)
					{
						mArray[k - 1] |= (1 << 31);
					}
					else
					{
						mArray[k - 1] &= ~(1 << 31);
					}
					mArray[k] >>= 1;
				}
				mSize--;
				return true;
			}
		}
		return false;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(size_t index) const
	{
		size_t arrIndex = index / 32;
		size_t arrBit = index % 32;
		return (mArray[arrIndex] >> arrBit) & 1;
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](size_t index) const
	{
		size_t arrIndex = index / 32;
		size_t arrBit = index % 32;
		return (mArray[arrIndex] >> arrBit) & 1;
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool bT) const
	{
		if (mSize == 0)
		{
			return -1;
		}
		size_t i = 0;
		size_t arrSize = (mSize % 32 != 0) ? (mSize / 32 + 1) : (mSize / 32);
		for (; i < arrSize - 1; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (((mArray[i] >> j) & 1) == bT)
				{
					return 32 * i + j;
				}
			}
		}
		size_t bitLength = (mSize % 32 != 0) ? (mSize % 32) : 32;
		for (size_t j = 0; j < bitLength; ++j)
		{
			if (((mArray[i] >> j) & 1) == bT)
			{
				return 32 * i + j;
			}
		}
		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}

	template<size_t N>
	void FixedVector<bool, N>::removeBit(size_t currentArrIndex, size_t removalIndex)
	{
		size_t temp = 0;
		for (size_t i = 0; i < removalIndex; ++i)
		{
			if ((mArray[currentArrIndex] >> i) & 1)
			{
				temp |= (1 << i);
			}
			else
			{
				temp &= ~(1 << i);
			}
		}
		mArray[currentArrIndex] >>= 1;
		for (size_t i = 0; i < removalIndex; ++i)
		{
			mArray[currentArrIndex] &= ~(1 << i);
		}
		mArray[currentArrIndex] |= temp;
	}
}
