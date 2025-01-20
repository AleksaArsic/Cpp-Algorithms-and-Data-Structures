#include <iostream>
#include "ArrayDequeue.hpp"

int main()
{
    ArrayDequeue::CircularDequeue dequeue(10);

    std::cout << dequeue << std::endl;
    std::cout << "dequeue.isEmpty() = " << dequeue.isEmpty() << std::endl;
    std::cout << "dequeue.isFull() = " << dequeue.isFull() << std::endl;
    //std::cout << "dequeue.popFront() = " << dequeue.popFront() << std::endl;
    //std::cout << "dequeue.popBack() = " << dequeue.popBack() << std::endl;
    std::cout << "dequeue.first() = " << dequeue.first() << std::endl;
    std::cout << "dequeue.last() = " << dequeue.last() << std::endl;


    for (unsigned int i = 0; i < 3; ++i)
    {
        dequeue.pushBack(i + 1);
        std::cout << dequeue << std::endl;
    }

    for (unsigned int i = 5; i < 10; ++i)
    {
        dequeue.pushFront(i + 1);
        std::cout << dequeue << std::endl;
    }

    std::cout << "dequeue.first() = " << dequeue.first() << std::endl;
    std::cout << "dequeue.last() = " << dequeue.last() << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 2; ++i)
    {
        std::cout << dequeue.popBack() << " ";
    }

    for (unsigned int i = 0; i < 2; ++i)
    {
        std::cout << dequeue.popFront() << " ";
    }
    std::cout << std::endl;
    std::cout << dequeue << std::endl;
    std::cout << std::endl;

    std::cout << "After dequeueing: " << dequeue << std::endl;
    std::cout << "dequeue.first() = " << dequeue.first() << std::endl;
    std::cout << "dequeue.last() = " << dequeue.last() << std::endl;

    return 0;
}