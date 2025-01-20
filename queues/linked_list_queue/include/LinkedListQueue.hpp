#pragma once
#include <iostream>
#include <memory>

namespace LinkedListQueue
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class Queue final
    {
        public:
            Queue();

            void enqueue(const int x);
            [[nodiscard]] int dequeue();
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] int first() const;
            [[nodiscard]] int last() const;

            friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

        private:
            std::shared_ptr<Node> front;
            std::shared_ptr<Node> rear;
    };

}