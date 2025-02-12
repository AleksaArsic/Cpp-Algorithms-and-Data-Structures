#pragma once
#include <memory>
#include <iostream>
#include "ComplexTypes.hpp"

namespace LinkedListQueue
{
	class Queue final
	{
		public:
			Queue();

			void enqueue(const std::shared_ptr<ComplexTypes::TreeNode> treeNode);
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> dequeue();
			[[nodiscard]] bool isFull() const;
			[[nodiscard]] bool isEmpty() const;
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> first() const;
			[[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> last() const;

			friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

		private:
			std::shared_ptr<ComplexTypes::Node> front;
			std::shared_ptr<ComplexTypes::Node> back;
	};
}