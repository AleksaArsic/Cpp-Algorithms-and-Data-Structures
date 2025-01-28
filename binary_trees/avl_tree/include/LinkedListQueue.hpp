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

            void enqueue(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node);
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> dequeue();
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> first() const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> last() const;

            friend std::ostream& operator<<(std::ostream& os, const Queue& queue);
            
        private:
            std::shared_ptr<ComplexTypes::TreeNode> front;
            std::shared_ptr<ComplexTypes::TreeNode> back;
    };
}