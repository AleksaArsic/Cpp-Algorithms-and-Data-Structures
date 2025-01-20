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

    class Stack final
    {
        public:
            Stack() : top(nullptr) 
            { }

            void push(const int data);
            int pop();
            [[nodiscard]] int peek(int index) const;
            [[nodiscard]] int stackTop() const;
            [[nodisacrd]] bool isEmpty() const;
            [[nodiscard]] bool isFull() const;

            friend std::ostream& operator<<(std::ostream& os, const Stack& s);

        private:
            std::shared_ptr<Node> top;

            [[nodiscard]] unsigned int countNodes() const;
    };
}