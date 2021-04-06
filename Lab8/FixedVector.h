#pragma once
#include <cassert>
#include <cstring>
using namespace std;
namespace lab8
{
	template <typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other);
		FixedVector<T, N>& operator=(const FixedVector& rhs);
		~FixedVector() = default;
		bool Add(const T& t);
		bool Remove(const T& t);
		T Get(size_t index) const;
		T& operator[](size_t index);
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		T mArray[N];
	};
	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
		memset(mArray, 0, N);
	}

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector& other)
		: mSize(other.mSize)
	{
		if (is_pointer<T>::value)
		{
			for (size_t i = 0; i < mSize; ++i)
			{
				mArray[i] = new T * (other->mArray[i]);
			}
		}
		else
		{
			for (size_t i = 0; i < mSize; ++i)
			{
				mArray[i] = other.mArray[i];
			}
		}
	}

	template <typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (is_pointer<T>::value)
		{
			for (auto& element : mArray)
			{
				element = nullptr;
			}
			mSize = rhs.mSize;
			for (int i = 0; i < mSize; ++i)
			{
				mArray[i] = new T * (rhs->mArray[i]);
			}
		}
		else
		{
			for (auto& element : mArray)
			{
				element = NULL;
			}
			mSize = rhs.mSize;
			for (int i = 0; i < mSize; ++i)
			{
				mArray[i] = rhs.mArray[i];
			}
		}
		return *this;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}
		mArray[mSize++] = t;
		return true;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		if (mSize == 0)
		{
			return false;
		}
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == t)
			{
				size_t j = i;
				for (; j < mSize; ++j)
				{
					mArray[j] = mArray[j + 1];
				}
				mSize--;
				return true;
			}
		}
		return false;
	}
	template <typename T, size_t N>
	T FixedVector<T, N>::Get(size_t index) const
	{
		assert(index < mSize);
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](size_t index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		if (mSize == 0)
		{
			return -1;
		}
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == t)
			{
				return i;
			}
		}
		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}
