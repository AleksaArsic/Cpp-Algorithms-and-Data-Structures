
#pragma once 
#include <iostream>
#include <memory>

namespace PriorityQueues
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class QueueInterface
    {
        public:
            QueueInterface();

            virtual void enqueue(const int x) = 0;
            [[nodiscard]] virtual int dequeue() = 0;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] int first() const;
            [[nodiscard]] int last() const;

            friend std::ostream& operator<<(std::ostream& os, const QueueInterface& queue);
        protected:
            std::shared_ptr<Node> front;
            std::shared_ptr<Node> rear;
    };
}