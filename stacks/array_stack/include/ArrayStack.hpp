#pragma once
#include <iostream>
#include <memory>

namespace ArrayStack
{
    class Stack final
    {
        public:
            Stack();

            Stack(unsigned int sizeOfStack);

            void push(const int data);
            int pop();
            [[nodiscard]] int peek(int index) const;
            [[nodiscard]] int stackTop() const;
            [[nodisacrd]] bool isEmpty() const;
            [[nodiscard]] bool isFull() const;

            friend std::ostream& operator<<(std::ostream& os, const Stack& s);

        private:
            unsigned int size;
            int top;
            std::shared_ptr<int[]> stack;
    };
}