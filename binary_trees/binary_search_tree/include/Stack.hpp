#pragma once
#include <iostream>
#include <memory>
#include "ComplexTypes.hpp"

namespace LinkedListStack
{
    class Stack final
    {
        public:
            Stack();

            void push(const std::shared_ptr<ComplexTypes::TreeNode>& node, const bool alreadyPushed = false);
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> pop();
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isTopAlreadyPushed() const;
            [[noidscard]] unsigned int stackSize() const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> stackTop() const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> peek(const unsigned int position) const;
            
            friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

        private:
            std::shared_ptr<ComplexTypes::Node> top;
    };
}