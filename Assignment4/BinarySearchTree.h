#pragma once
#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree() = default;
		~BinarySearchTree() = default;
		BinarySearchTree(const BinarySearchTree<T>& other) = default;
		BinarySearchTree& operator=(const BinarySearchTree<T>& rhs) = default;
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		static void traverseInOrderDfs(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& vec);
		std::shared_ptr<TreeNode<T>> findMinValueNode(const std::shared_ptr<TreeNode<T>> startNode);
		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}
		auto temp = mRoot;
		while (temp != nullptr)
		{
			if (*data <= *temp->Data && temp->Left == nullptr)
			{
				auto newNode = std::make_shared<TreeNode<T>>(temp, std::move(data));
				temp->Left = newNode;
				return;
			}
			else if (*data <= *(temp->Data))
			{
				temp = temp->Left;
			}
			else if (*data > *temp->Data && temp->Right == nullptr)
			{
				auto newNode = std::make_shared<TreeNode<T>>(temp, std::move(data));
				temp->Right = newNode;
				return;
			}
			else
			{
				temp = temp->Right;
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mRoot == nullptr)
		{
			return false;
		}
		auto temp = mRoot;
		while (temp != nullptr)
		{
			if (data == *temp->Data)
			{
				return true;
			}
			if (data < *temp->Data)
			{
				temp = temp->Left;
			}
			else
			{
				temp = temp->Right;
			}
		}
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		auto temp = mRoot;
		if (mRoot == nullptr)
		{
			return false;
		}
		while (temp != nullptr)
		{
			if (data < *temp->Data)
			{
				temp = temp->Left;
			}
			else if (data > *temp->Data)
			{
				temp = temp->Right;
			}
			else
			{
				if (temp->Left == nullptr && temp->Right == nullptr)
				{
					auto tempParent = temp->Parent.lock();
					if (tempParent == nullptr)
					{
						mRoot = nullptr;
						return true;
					}
					if (*temp->Data > *tempParent->Data)
					{
						tempParent->Right = nullptr;
					}
					else
					{
						tempParent->Left = nullptr;
					}
					return true;
				}
				else if (temp->Left == nullptr)
				{
					auto res = temp->Right;
					auto tempParent = temp->Parent.lock();
					if (tempParent == nullptr)
					{
						mRoot = res;
						return true;
					}
					if (*temp->Data > *tempParent->Data)
					{
						tempParent->Right = res;
						res->Parent = tempParent;
					}
					else
					{
						tempParent->Left = res;
						res->Parent = tempParent;
					}
					return true;
				}
				else if (temp->Right == nullptr)
				{
					auto res = temp->Left;
					auto tempParent = temp->Parent.lock();
					if (tempParent == nullptr)
					{
						mRoot = res;
						return true;
					}
					if (*temp->Data > *tempParent->Data)
					{
						tempParent->Right = res;
						res->Parent = tempParent;
					}
					else
					{
						tempParent->Left = res;
						res->Parent = tempParent;
					}
					return true;
				}
				else
				{
					auto res = findMinValueNode(temp->Right);
					T& tempData = *res->Data;
					Delete(tempData);
					*temp->Data = tempData;
					return true;
				}
			}
		}
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		if (startNode == nullptr)
		{
			return v;
		}
		traverseInOrderDfs(startNode->Left, v);
		v.push_back(*startNode->Data);
		traverseInOrderDfs(startNode->Right, v);
		return v;
	}
	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::findMinValueNode(const std::shared_ptr<TreeNode<T>> startNode)
	{
		auto current = startNode;
		while (current->Left != nullptr)
		{
			current = current->Left;
		}
		return current;
	}
	template<typename T>
	void BinarySearchTree<T>::traverseInOrderDfs(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& vec)
	{
		if (startNode == nullptr)
		{
			return;
		}
		traverseInOrderDfs(startNode->Left, vec);
		vec.push_back(*startNode->Data);
		traverseInOrderDfs(startNode->Right, vec);
	}
}