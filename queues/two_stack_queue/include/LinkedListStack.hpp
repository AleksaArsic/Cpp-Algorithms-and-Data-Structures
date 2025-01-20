#pragma once
#include <iostream>
#include <memory>

namespace LinkedListStack
{
    struct Node
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class Stack
    {
        public:
            Stack();

            void push(const int data);
            [[nodiscard]] int pop();
            [[nodiscard]] int stackTop() const;
            [[nodiscard]] int peek(const unsigned int position) const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] int stackSize() const;

            friend std::ostream& operator<<(std::ostream& os, const Stack stack);
        private:
            std::shared_ptr<Node> top;

            [[nodiscard]] unsigned int countNodes() const;
    };
}