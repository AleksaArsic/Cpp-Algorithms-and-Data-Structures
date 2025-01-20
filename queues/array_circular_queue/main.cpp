#include <iostream>
#include "CircularArrayQueue.hpp"

int main()
{
    CircularArrayQueue::CircularQueue circularQueue(10);

    std::cout << circularQueue << std::endl;
    std::cout << "queue.isEmpty() = " << circularQueue.isEmpty() << std::endl;
    std::cout << "queue.isFull() = " << circularQueue.isFull() << std::endl;
    std::cout << "queue.dequeue() = " << circularQueue.dequeue() << std::endl;
    std::cout << "queue.first() = " << circularQueue.first() << std::endl;
    std::cout << "queue.last() = " << circularQueue.last() << std::endl;


    for (unsigned int i = 0; i < 12; ++i)
    {
        circularQueue.enqueue(i + 1);
        std::cout << circularQueue << std::endl;
    }

    std::cout << "queue.first() = " << circularQueue.first() << std::endl;
    std::cout << "queue.last() = " << circularQueue.last() << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::cout << circularQueue.dequeue() << " ";
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << circularQueue << std::endl;
    std::cout << "queue.first() = " << circularQueue.first() << std::endl;
    std::cout << "queue.last() = " << circularQueue.last() << std::endl;

    return 0;
}