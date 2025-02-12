#include "LinkedListQueue.hpp"

namespace LinkedListQueue
{
	// Time complexity -> o(1)
	// Space complexity -> o(1)
	Queue::Queue() : front(nullptr), back(nullptr)
	{ }

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	void Queue::enqueue(const std::shared_ptr<ComplexTypes::TreeNode> treeNode)
	{
		if (!isFull())
		{
			bool isAlreadyStored = false;
			std::shared_ptr<ComplexTypes::Node> newNode = std::make_shared<ComplexTypes::Node>(isAlreadyStored, treeNode, nullptr);

			if (isEmpty())
			{
				front = back = newNode;
			}
			else
			{
				back->next = newNode;
				back = back->next;
			}
		}
		else
		{
			std::cout << "Queue is full." << std::endl;
		}
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Queue::dequeue()
	{
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;
		std::shared_ptr<ComplexTypes::Node> node = front;

		if (!isEmpty())
		{
			treeNode = node->treeNode;
			front = front->next;
			node.reset();
		}
		else
		{
			std::cout << "Queue is empty." << std::endl;
		}

		return treeNode;
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] bool Queue::isFull() const
	{
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>
															(ComplexTypes::NodeColorClass::NodeColor::RED, INT_MIN, nullptr, nullptr);
		bool isAlreadyStored = false;
		std::shared_ptr<ComplexTypes::Node> node = std::make_shared<ComplexTypes::Node>(isAlreadyStored, treeNode, nullptr);

		return (treeNode == nullptr || node == nullptr);
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] bool Queue::isEmpty() const
	{
		return (front == nullptr);
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Queue::first() const
	{
		return (front == nullptr) ? nullptr : front->treeNode;
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Queue::last() const
	{
		return (back == nullptr) ? nullptr : back->treeNode;
	}

	// Time complexity -> o(n)
	// Space complexity -> o(1)
	std::ostream& operator<<(std::ostream& os, const Queue& queue)
	{
		std::shared_ptr<ComplexTypes::Node> node = queue.front;

		while (node != nullptr)
		{
			std::cout << "(" << node->treeNode->data << ", " << node->treeNode->color << ") ";
			node = node->next;
		}

		return os;
	}
}