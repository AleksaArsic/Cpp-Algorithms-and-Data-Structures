#pragma once
#include <memory>
#include <iostream>
#include "ComplexTypes.hpp"

namespace LinkedListStack
{
	class Stack final
	{
		public:
			Stack();

			void push(const std::shared_ptr<ComplexTypes::TreeNode>& node, const bool alreadyPushed = false);
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> pop();
			[[nodiscard]] bool isFull() const;
			[[nodiscard]] bool isEmpty() const;
			[[nodiscard]] unsigned int stackSize() const;
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> stackTop() const;
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> peek(const unsigned int position) const;
			[[nodiscard]] bool isTopAlreadyPushed() const;

			friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

		private:
			std::shared_ptr<ComplexTypes::StackNode> top;

	};
}