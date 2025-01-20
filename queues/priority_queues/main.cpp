#include <iostream>
#include "PriorityQueue.hpp"
#include "IncreasingPriorityQueue.hpp"

void testPriorityQueue(PriorityQueues::QueueInterface& queue)
{
    std::cout << queue << std::endl;
    std::cout << "queue.isEmpty() = " << queue.isEmpty() << std::endl;
    std::cout << "queue.isFull() = " << queue.isFull() << std::endl;
    std::cout << "queue.dequeue() = " << queue.dequeue() << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;


    for (unsigned int i = 0; i < 6; i+=2)
    {
        queue.enqueue(i + 1);
        std::cout << queue << std::endl;
    }

    for (unsigned int i = 12; i > 6; i -= 2)
    {
        queue.enqueue(i + 1);
        std::cout << queue << std::endl;
    }

    queue.enqueue(4);
    queue.enqueue(33);
    queue.enqueue(-1);
    std::cout << queue << std::endl;

    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 5; ++i)
    {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << queue << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;
}

int main()
{
    PriorityQueues::PriorityQueue priorityQueue;
    PriorityQueues::IncreasingPriorityQueue increasingPriorityQueue;

    testPriorityQueue(priorityQueue);
    testPriorityQueue(increasingPriorityQueue);

    return 0;
}