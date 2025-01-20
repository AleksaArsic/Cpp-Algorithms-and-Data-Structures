#pragma once
#include <iostream>
#include <memory>

namespace LinkedListDequeue
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class Dequeue final
    {
        public:
            Dequeue();

            void pushFront(const int data);
            void pushRear(const int data);
            [[nodiscard]] int popFront();
            [[nodiscard]] int popRear();
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] int first() const;
            [[nodiscard]] int last() const;

            friend std::ostream& operator<<(std::ostream& os, const Dequeue& dequeue);
        private:
            std::shared_ptr<Node> front;
            std::shared_ptr<Node> rear; 
    };
}