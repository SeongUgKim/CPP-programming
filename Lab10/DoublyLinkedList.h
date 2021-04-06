#pragma once
#include <cassert>
#include <memory>
#include "Node.h"
namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mHead;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0)
		, mHead(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		// add new node at the end
		std::shared_ptr<Node<T>> newNode;
		auto temp = mHead;
		if (temp == nullptr)
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			mHead = newNode;
			mLength++;
			return;
		}
		while (temp->Next != nullptr)
		{
			temp = temp->Next;
		}
		newNode = std::make_shared<Node<T>>(std::move(data), temp);
		temp->Next = newNode;
		mLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength || mLength == 0)
		{
			Insert(std::move(data));
			return;
		}
		std::shared_ptr<Node<T>> newNode;
		if (index == 0)
		{
			assert(mHead->Next != nullptr);
			auto next = mHead;
			newNode = std::make_shared<Node<T>>(std::move(data), nullptr);
			mHead = newNode;
			newNode->Next = next;
			next->Previous = newNode;
			mLength++;
			return;
		}
		unsigned int currentIndex = 1;
		auto temp = mHead;
		while (temp->Next != nullptr && currentIndex != index)
		{
			temp = temp->Next;
			currentIndex++;
		}
		newNode = std::make_shared<Node<T>>(std::move(data), temp);
		newNode->Next = temp->Next;
		temp->Next->Previous = newNode;
		temp->Next = newNode;
		mLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mLength == 0)
		{
			return false;
		}
		auto temp = mHead;
		while (temp != nullptr && *(temp->Data) != data)
		{
			temp = temp->Next;
		}
		if (temp == mHead)
		{
			if (temp->Next == nullptr)
			{
				mHead = nullptr;
				mLength--;
				return true;
			}
			mHead = temp->Next;
			temp->Next->Previous.lock() = nullptr;
			temp->Next = nullptr;
			mLength--;
			return true;
		}
		if (temp == nullptr)
		{
			return false;
		}
		if (temp->Next == nullptr)
		{
			auto prevNode = temp->Previous.lock();
			prevNode->Next = nullptr;
			temp->Previous.lock() = nullptr;
			mLength--;
			return true;
		}
		auto prevNode = temp->Previous.lock();
		auto nextNode = temp->Next;
		prevNode->Next = nextNode;
		nextNode->Previous = prevNode;
		temp->Next = nullptr;
		temp->Previous.lock() = nullptr;
		mLength--;
		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		if (mLength == 0)
		{
			return false;
		}
		auto temp = mHead;
		while (temp != nullptr)
		{
			if (*(temp->Data) == data)
			{
				return true;
			}
			temp = temp->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mLength || mLength == 0)
		{
			return nullptr;
		}
		std::shared_ptr<Node<T>> temp = mHead;
		unsigned int currentIndex = 0;
		while (temp != nullptr && currentIndex != index)
		{
			temp = temp->Next;
			currentIndex++;
		}
		return temp;

	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}
