#include <iostream>
#include "TwoStackQueue.hpp"
#include "LinkedListStack.hpp"

void testStack(LinkedListStack::Stack& stack)
{
    std::cout << "******************************** Test Stack ********************************" << std::endl;
    std::cout << stack << std::endl;

    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.pop() = " << stack.pop() << std::endl;

    for (unsigned int i = 0; i < 12; ++i)
    {
        stack.push(i + 1);
        std::cout << stack << std::endl;
    }

    std::cout << "stack.stackTop() = " << stack.stackTop() << std::endl;
    std::cout << "stack.peek(3) = " << stack.peek(3) << std::endl;
    std::cout << "stack.peek(5) = " << stack.peek(5) << std::endl;
    std::cout << "stack.peek(9) = " << stack.peek(9) << std::endl;
    std::cout << "stack.peek(10) = " << stack.peek(10) << std::endl;
    std::cout << "stack.peek(0) = " << stack.peek(0) << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    std::cout << "Stack popping: ";
    for (unsigned int i = 0; i < 6; ++i)
    {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
    std::cout << "Stack after popping: " << stack << std::endl;

    std::cout << "stack.stackTop() = " << stack.stackTop() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;


    std::cout << "****************************************************************************" << std::endl;
}

int main()
{
    TwoStackQueue::Queue queue;
    LinkedListStack::Stack stack;

    testStack(stack);

    std::cout << queue << std::endl;
    std::cout << "queue.isEmpty() = " << queue.isEmpty() << std::endl;
    std::cout << "queue.isFull() = " << queue.isFull() << std::endl;
    std::cout << "queue.dequeue() = " << queue.dequeue() << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;


    for (unsigned int i = 0; i < 12; ++i)
    {
        queue.enqueue(i + 1);
        std::cout << queue << std::endl;
    }

    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << queue << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;

    return 0;
}