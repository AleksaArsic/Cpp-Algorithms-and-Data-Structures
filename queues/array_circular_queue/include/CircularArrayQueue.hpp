#pragma once
#include <iostream>
#include <memory>

namespace CircularArrayQueue
{
    class CircularQueue final
    {
        public:
            CircularQueue() = delete;
            CircularQueue(const int size);

            void enqueue(const int x);
            [[nodiscard]] int dequeue();
            [[nodiscard]] bool isEmpty() const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] int first() const;
            [[nodiscard]] int last() const;

            friend std::ostream& operator<<(std::ostream& os, const CircularQueue cq);
            
        private:
            int arraySize;
            int front;
            int rear;
            std::shared_ptr<int[]> array;
    };
}