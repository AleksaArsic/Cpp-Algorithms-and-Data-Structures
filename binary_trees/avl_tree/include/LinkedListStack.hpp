#pragma once
#include <iostream>
#include "ComplexTypes.hpp"

namespace LinkedListStack
{
    class Stack final
    {
        public:
            Stack();

            void push(const std::shared_ptr<ComplexTypes::AVLTreeNode>& treeNode, bool isAlreadyPushed = false);
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> pop();
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> stackTop() const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> peek(const unsigned int position) const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] unsigned int stackSize() const;
            [[nodiscard]] bool isTopAlreadyPushed() const;

            friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

        private:
            std::shared_ptr<ComplexTypes::TreeNode> top;
    };
}