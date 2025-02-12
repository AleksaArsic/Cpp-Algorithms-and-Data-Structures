#include "LinkedListStack.hpp"

namespace LinkedListStack
{
	// Time complexity -> o(1)
	// Space complexity -> o(1)
	Stack::Stack() : top(nullptr)
	{

	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	void Stack::push(const std::shared_ptr<ComplexTypes::TreeNode>& node, const bool alreadyPushed)
	{

		if (!isFull())
		{
			if (node != nullptr)
			{
				std::shared_ptr<ComplexTypes::Node> newNode = std::make_shared<ComplexTypes::Node>(alreadyPushed, node, top);
				top = newNode;
			}
			else
			{
				std::cout << "Trying to push nullptr." << std::endl;
			}
		}
		else
		{
			std::cout << "Stack is full." << std::endl;
		}
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::pop()
	{
		std::shared_ptr<ComplexTypes::TreeNode> node = nullptr;

		if (!isEmpty())
		{
			node = top->treeNode;
			top = top->next;
		}
		else
		{
			std::cout << "Stack is empty." << std::endl;
		}

		return node;
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::stackTop() const
	{
		return (top != nullptr) ? top->treeNode : nullptr;
	}

	// Time complexity -> o(n)
	// Space complexity -> o(1)
	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::peek(const unsigned int position) const
	{
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;
		std::shared_ptr<ComplexTypes::Node> node = top;

		if (position < stackSize())
		{
			for (unsigned int i = 0; i < position; ++i)
			{
				node = node->next;
			}

			treeNode = node->treeNode;
		}
		else
		{
			std::cout << "Position argument out of range." << std::endl;
		}

		return treeNode;
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] bool Stack::isFull() const
	{
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>
																(ComplexTypes::NodeColorClass::NodeColor::RED, INT_MIN, nullptr, nullptr);
		std::shared_ptr<ComplexTypes::Node> node = std::make_shared<ComplexTypes::Node>(false, treeNode, nullptr);

		return (treeNode == nullptr || node == nullptr);
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] bool Stack::isEmpty() const
	{
		return (top == nullptr);
	}

	// Time complexity -> o(1)
	// Space complexity -> o(1)
	[[nodiscard]] bool Stack::isTopAlreadyPushed() const
	{
		return (top == nullptr) ? false : top->isAlreadyStored;
	}

	// Time complexity -> o(n)
	// Space complexity -> o(1)
	[[nodiscard]] unsigned int Stack::stackSize() const
	{
		unsigned int nodeCount = 0;
		std::shared_ptr<ComplexTypes::Node> node = top;

		while (node != nullptr)
		{
			++nodeCount;
			node = node->next;
		}

		return nodeCount;
	}

	// Time complexity -> o(n)
	// Space complexity -> o(1)
	std::ostream& operator<<(std::ostream& os, const Stack& stack)
	{
		std::shared_ptr<ComplexTypes::Node> node = stack.top;

		while (node != nullptr)
		{
			std::cout << "(" << node->treeNode->data << ", " << node->treeNode->color << ") ";
			node = node->next;
		}

		return os;
	}
}