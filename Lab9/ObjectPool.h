#pragma once
#include <queue>
using namespace std;
namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& rhs) = delete;
		~ObjectPool();
		T* Get();
		void Return(T* object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mCapacity;
		queue<T*> mPool;
		
	};
	
	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mCapacity(maxPoolSize)
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (!mPool.empty())
		{
			T* temp = mPool.front();
			delete temp;
			temp = nullptr;
			mPool.pop();
		}
	}
	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mPool.empty())
		{
			return new T();
		}
		T* ret = mPool.front();
		mPool.pop();
		return ret;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mPool.size() == mCapacity)
		{
			delete object;
			object = nullptr;
			return;
		}
		mPool.push(object);
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mPool.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mCapacity;
	}
}