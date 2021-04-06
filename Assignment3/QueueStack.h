#pragma once
#include <cassert>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other);
		QueueStack<T>& operator=(const QueueStack& rhs);
		~QueueStack();
		void Enqueue(T number);
		inline T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		inline double GetAverage() const;
		inline T GetSum() const;
		inline unsigned int GetCount() const;
		inline unsigned int GetStackCount() const;
	private:
		void updateMaxValue(queue<stack<T>> q);
		void updateMinValue(queue<stack<T>> q);
		queue<stack<T>> mQueue;
		struct Variables
		{
			T Min;
			T Max;
			T Sum;
			unsigned int Count;
		};
		Variables* mVariables;
		unsigned int mMaxStackSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mVariables = new Variables();
		mVariables->Min = numeric_limits<T>::max();
		mVariables->Max = numeric_limits<T>::lowest();
		mVariables->Sum = 0;
		mVariables->Count = 0;
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& other)
		: mMaxStackSize(other.mMaxStackSize)
	{
		mQueue = other.mQueue;
		mVariables = new Variables();
		mVariables->Min = other.mVariables->Min;
		mVariables->Max = other.mVariables->Max;
		mVariables->Sum = other.mVariables->Sum;
		mVariables->Count = other.mVariables->Count;
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack& rhs)
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
		mVariables = new Variables();
		mVariables->Min = rhs.mVariables->Min;
		mVariables->Max = rhs.mVariables->Max;
		mVariables->Sum = rhs.mVariables->Sum;
		mVariables->Count = rhs.mVariables->Count;
		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		delete mVariables;
		mVariables = nullptr;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}
		if (mQueue.empty() || mQueue.back().size() == mMaxStackSize)
		{
			mQueue.push(stack<T>());
		}
		mQueue.back().push(number);
		mVariables->Sum += number;
		mVariables->Count++;
	}

	template<typename T>
	T QueueStack<T>::Peek() const
	{
		assert(!mQueue.empty());
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		assert(!mQueue.empty());
		assert(!mQueue.front().empty());
		T ret = mQueue.front().top();
		mQueue.front().pop();
		if (mQueue.front().empty())
		{
			mQueue.pop();
		}
		mVariables->Sum -= ret;
		mVariables->Count--;
		return ret;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		if (mQueue.empty())
		{
			return numeric_limits<T>::lowest();
		}
		updateMaxValue(mQueue);
		return mVariables->Max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		if (mQueue.empty())
		{
			return numeric_limits<T>::max();
		}
		updateMinValue(mQueue);
		return mVariables->Min;
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		return mVariables->Sum;
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		assert(!mQueue.empty());
		return mVariables->Sum / static_cast<double>(mVariables->Count);
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mVariables->Count;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mQueue.size();
	}

	template<typename T>
	void QueueStack<T>::updateMaxValue(queue<stack<T>> q)
	{
		mVariables->Max = q.front().top();
		q.front().pop();
		while (!q.empty())
		{
			while (q.front().size() != 0)
			{
				mVariables->Max = max(mVariables->Max, q.front().top());
				q.front().pop();
			}
			q.pop();
		}
	}

	template<typename T>
	void QueueStack<T>::updateMinValue(queue<stack<T>> q)
	{
		mVariables->Min = q.front().top();
		q.front().pop();
		while (!q.empty())
		{
			while (q.front().size() != 0)
			{
				mVariables->Min = min(mVariables->Min, q.front().top());
				q.front().pop();
			}
			q.pop();
		}
	}
}