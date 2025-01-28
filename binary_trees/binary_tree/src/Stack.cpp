#include "Stack.hpp"

namespace LinkedListStack
{
	Stack::Stack() : top(nullptr)
	{ }

	void Stack::push(const std::shared_ptr<ComplexTypes::TreeNode>& node, const bool alreadyPushed)
	{
		if (!isFull())
		{
			std::shared_ptr<ComplexTypes::StackNode> newNode = std::make_shared<ComplexTypes::StackNode>(alreadyPushed, node, top);
			top = newNode;
		}
		else
		{
			std::cout << "The stack is full." << std::endl;
		}
	}

	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::pop()
	{
		std::shared_ptr<ComplexTypes::StackNode> node = nullptr;
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;

		if (!isEmpty())
		{
			node = top;
			treeNode = node->data;
			top = top->next;
			node.reset();
		}
		else
		{
			std::cout << "Stack is empty." << std::endl;
		}

		return treeNode;
	}

	[[nodiscard]] bool Stack::isFull() const
	{
		std::shared_ptr<ComplexTypes::StackNode> node = std::make_shared<ComplexTypes::StackNode>(false, nullptr, nullptr);
		std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>(INT_MIN, nullptr, nullptr);

		return (node == nullptr || treeNode == nullptr);
	}

	[[nodiscard]] bool Stack::isEmpty() const
	{
		return (top == nullptr);
	}

	[[nodiscard]] unsigned int Stack::stackSize() const
	{
		std::shared_ptr<ComplexTypes::StackNode> node = top;
		unsigned int nodeCount = 0;

		while (node != nullptr)
		{
			nodeCount++;
			node = node->next;
		}

		return nodeCount;
	}

	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::stackTop() const
	{
		return (top == nullptr) ? nullptr : top->data;
	}

	[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::peek(const unsigned int position) const
	{
		std::shared_ptr<ComplexTypes::StackNode> node = top;

		if (position < stackSize())
		{
			for (unsigned int i = 0; i < position; ++i)
			{
				node = node->next;
			}
		}

		return (node == nullptr) ? nullptr : node->data;
	}

	[[nodiscard]] bool Stack::isTopAlreadyPushed() const
	{
		return top->isAlreadyPushed;
	}

	std::ostream& operator<<(std::ostream& os, const Stack& stack)
	{
		std::shared_ptr<ComplexTypes::StackNode> node = stack.top;

		while (node != nullptr)
		{
			std::cout << node->data->data << " ";
			node = node->next;
		}

		return os;
	}
}