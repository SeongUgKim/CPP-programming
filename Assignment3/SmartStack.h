#pragma once
#include <cassert>
#include <stack>
#include <limits>
using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack& other) = default;
		SmartStack& operator=(const SmartStack& rhs) = default;
		~SmartStack() = default;
		void Push(T number);
		T Pop();
		inline T Peek() const;
		T GetMax() const;
		T GetMin() const;
		inline double GetAverage() const;
		inline T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		inline unsigned int GetCount() const;
	private:
		stack<T> mStack;
		stack<T> mMinStack;
		stack<T> mMaxStack;
		T mSum;
		T mSquareSum;
		double mAnotherSum;
		double mAnotherSqSum;
		unsigned int mCount;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0)
		, mSquareSum(0)
		, mCount(0)
		, mAnotherSum(0.0)
		, mAnotherSqSum(0.0)
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
		if (mMinStack.empty())
		{
			mMinStack.push(number);
		}
		else 
		{
			T temp = mMinStack.top();
			if (temp >= number)
			{
				mMinStack.push(number);
			}
		}
		if (mMaxStack.empty())
		{
			mMaxStack.push(number);
		}
		else
		{
			T temp = mMaxStack.top();
			if (temp <= number)
			{
				mMaxStack.push(number);
			}
		}
		mSum += number;
		mSquareSum += (number * number);
		mAnotherSum += static_cast<double>(number);
		mAnotherSqSum += pow(static_cast<double>(number), 2.0);
		mCount++;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		assert(!mStack.empty());
		T ret = mStack.top();
		if (!mMinStack.empty() && ret == mMinStack.top())
		{
			mMinStack.pop();
		}
		if (!mMaxStack.empty() && ret == mMaxStack.top())
		{
			mMaxStack.pop();
		}
		mStack.pop();
		mSum -= ret;
		mSquareSum -= (ret * ret);
		mAnotherSum -= static_cast<double>(ret);
		mAnotherSqSum -= pow(static_cast<double>(ret), 2.0);
		mCount--;
		return ret;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		assert(!mStack.empty());
		return mStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		if (mStack.empty())
		{
			return numeric_limits<T>::lowest();
		}
		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		if (mStack.empty())
		{
			return numeric_limits<T>::max();
		}
		return mMinStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		assert(!mStack.empty());
		double average = mSum / static_cast<double>(mCount);
		return average;
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		assert(!mStack.empty());
		double average = mAnotherSum / static_cast<double>(mCount);
		double squareAverage = mAnotherSqSum / static_cast<double>(mCount);
		double variance = squareAverage - (average * average);
		return variance;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		assert(!mStack.empty());
		double average = mAnotherSum / static_cast<double>(mCount);
		double squareAverage = mAnotherSqSum / static_cast<double>(mCount);
		double variance = squareAverage - (average * average);
		double standardDeviation = sqrt(variance);
		return standardDeviation;
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mStack.size();
	}
}