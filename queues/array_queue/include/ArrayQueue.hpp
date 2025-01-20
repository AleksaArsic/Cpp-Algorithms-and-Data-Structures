#pragma once
#include <memory>
#include <iostream>

namespace ArrayQueue
{
    class Queue final
    {
    public:
        Queue() = delete;
        Queue(const int size);

        void enqueue(const int x);
        [[nodiscard]] int dequeue();
        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] bool isFull() const;
        [[nodiscard]] int first() const;
        [[nodiscard]] int last() const;

        friend std::ostream& operator<<(std::ostream& os, const Queue queue);
    private:
        int arraySize;
        int front;
        int rear;
        std::shared_ptr<int[]> array;
    };
}