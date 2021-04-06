#pragma once
#include <limits>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue<T>& operator=(const SmartQueue& rhs);
		~SmartQueue();
		void Enqueue(T number);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		inline double GetAverage() const;
		inline T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		inline unsigned int GetCount() const;
	private:
		void updateMinValue(queue<T> q);
		void updateMaxValue(queue<T> q);
		queue<T> mQueue;
		struct Variables
		{
			T Sum;
			T SqSum;
			T Min;
			T Max;
		};
		Variables* mVariables;
		double mAnotherSum;
		double mAnotherSqSum;
		unsigned int mCount;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mAnotherSum(0.0)
		, mAnotherSqSum(0.0)
		, mCount(0)
	{
		mVariables = new Variables();
		mVariables->Sum = 0;
		mVariables->SqSum = 0;
		mVariables->Min = numeric_limits<T>::max();
		mVariables->Max = numeric_limits<T>::lowest();
	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other)
		: mAnotherSum(other.mAnotherSum)
		, mAnotherSqSum(other.mAnotherSqSum)
		, mCount(other.mCount)
	{
		mQueue = other.mQueue;
		mVariables = new Variables();
		mVariables->Sum = other.mVariables->Sum;
		mVariables->SqSum = other.mVariables->SqSum;
		mVariables->Min = other.mVariables->Min;
		mVariables->Max = other.mVariables->Max;
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (mVariables != nullptr)
		{
			delete mVariables;
			mVariables = nullptr;
		}
		mQueue = rhs.mQueue;
		mAnotherSum = rhs.mAnotherSum;
		mAnotherSqSum = rhs.mAnotherSqSum;
		mCount = rhs.mCount;
		mVariables = new Variables();
		mVariables->Sum = rhs.mVariables->Sum;
		mVariables->SqSum = rhs.mVariables->SqSum;
		mVariables->Min = rhs.mVariables->Min;
		mVariables->Max = rhs.mVariables->Max;
		return *this;
	}

	template<typename T>
	SmartQueue<T>::~SmartQueue()
	{
		delete mVariables;
		mVariables = nullptr;
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mVariables->Sum += number;
		mVariables->SqSum += (number * number);
		mAnotherSum += static_cast<double>(number);
		mAnotherSqSum += pow(static_cast<double>(number), 2.0);
		mCount++;
	}

	template<typename T>
	T SmartQueue<T>::Peek() const
	{
		assert(!mQueue.empty());
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		assert(!mQueue.empty());
		T ret = mQueue.front();
		mQueue.pop();
		mVariables->Sum -= ret;
		mVariables->SqSum -= (ret * ret);
		mAnotherSum -= static_cast<double>(ret);
		mAnotherSqSum -= pow(static_cast<double>(ret), 2.0);
		mCount--;
		return ret;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return numeric_limits<T>::lowest();
		}
		assert(!mQueue.empty());
		updateMaxValue(mQueue);
		return mVariables->Max;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return numeric_limits<T>::max();
		}
		assert(!mQueue.empty());
		updateMinValue(mQueue);
		return mVariables->Min;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		assert(!mQueue.empty());
		return mVariables->Sum / static_cast<double>(mCount);
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mVariables->Sum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		assert(!mQueue.empty());
		double average = mAnotherSum / static_cast<double>(mCount);
		double sqAverage = mAnotherSqSum / static_cast<double>(mCount);
		double variance = sqAverage - (average * average);
		return variance;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		assert(!mQueue.empty());
		double average = mAnotherSum / static_cast<double>(mCount);
		double sqAverage = mAnotherSqSum / static_cast<double>(mCount);
		double variance = sqAverage - (average * average);
		double standardDeviation = sqrt(variance);
		return standardDeviation;
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mCount;
	}

	template<typename T>
	void SmartQueue<T>::updateMaxValue(queue<T> q)
	{
		assert(!q.empty());
		mVariables->Max = q.front();
		q.pop();
		while (!q.empty())
		{
			mVariables->Max = max(mVariables->Max, q.front());
			q.pop();
		}
	}

	template<typename T>
	void SmartQueue<T>::updateMinValue(queue<T> q)
	{
		assert(!q.empty());
		{
			mVariables->Min = q.front();
			q.pop();
			while (!q.empty())
			{
				mVariables->Min = min(mVariables->Min, q.front());
				q.pop();
			}
		}
	}
}
