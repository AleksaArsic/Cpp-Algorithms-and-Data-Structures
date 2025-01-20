#pragma once
#include <iostream>
#include <memory>

namespace LinkedListStack
{
    struct Data final
    {
        char character;
        char precedence;
    };

    struct Node final
    {
        Data data;
        std::shared_ptr<Node> next;
    };

    class Stack final
    {
        public:
            Stack() : top(nullptr)
            { }

            void push(const char data, const char precedence);
            [[nodiscard]] const Data& pop();
            [[nodiscard]] const Data& stackTop() const;
            [[nodiscard]] const Data& peek(const unsigned int position) const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;

            friend std::ostream& operator<<(std::ostream& os, const Stack& s);

        private:
            std::shared_ptr<Node> top;

            [[nodiscard]] unsigned int nodeCount() const;
    };
}