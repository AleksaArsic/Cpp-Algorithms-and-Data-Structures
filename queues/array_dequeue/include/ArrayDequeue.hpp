#pragma once
#include <iostream>
#include <memory>

namespace ArrayDequeue
{
    // Dequeue can be with restricted input or output
    // Input restricted dequeue cannot push to front
    // Output restricted dequeue cannot delete from rear
    // This implementation is without restrictions
    class CircularDequeue final
    {
        public:
            CircularDequeue() = delete;
            CircularDequeue(const unsigned int size);
            
            void pushFront(const int data);
            void pushBack(const int data);
            [[nodiscard]] int popFront();
            [[nodiscard]] int popBack();
            [[nodiscard]] int first() const;
            [[nodiscard]] int last() const;
            [[nodiscard]] bool isFull() const;
            [[nodiscard]] bool isEmpty() const;

            friend std::ostream& operator<<(std::ostream& os, const CircularDequeue& dequeue);
        private:
            unsigned int dequeueSize;
            int front;
            int rear;
            std::shared_ptr<int[]> array;
    };
}