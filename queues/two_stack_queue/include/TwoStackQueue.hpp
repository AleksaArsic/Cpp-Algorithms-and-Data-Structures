#pragma once
#include <iostream>
#include <memory>
#include "LinkedListStack.hpp"

namespace TwoStackQueue
{
    class Queue final
    {
        public:
            Queue() = default;

            void enqueue(const int data);
            [[nodiscard]] int dequeue();
            [[nodiscard]] bool isEmpty();
            [[nodiscard]] bool isFull();
            [[nodiscard]] int first();
            [[nodiscard]] int last();

            friend std::ostream& operator<<(std::ostream& os, const Queue& queue);
        private:
            LinkedListStack::Stack stackOne;
            LinkedListStack::Stack stackTwo;
    };
}