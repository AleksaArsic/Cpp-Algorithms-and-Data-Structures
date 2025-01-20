#include "LinkedListStackTest.hpp"

void testStack(LinkedListStack::Stack& stack)
{
    std::cout << "******************************** Test Stack ********************************" << std::endl;
    std::cout << stack << std::endl;

    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.pop() = " << stack.pop().character << std::endl;
    for (unsigned int i = 'A'; i < 'G'; ++i)
    {
        stack.push(i, '0');
        std::cout << stack << std::endl;
    }

    std::cout << "stack.stackTop() = " << stack.stackTop().character << std::endl;
    std::cout << "stack.peek(3) = " << stack.peek(3).character << std::endl;
    std::cout << "stack.peek(5) = " << stack.peek(5).character << std::endl;
    std::cout << "stack.peek(9) = " << stack.peek(9).character << std::endl;
    std::cout << "stack.peek(10) = " << stack.peek(10).character << std::endl;
    std::cout << "stack.peek(0) = " << stack.peek(0).character << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    std::cout << "stack.pop(): ";
    for (unsigned int i = 'A'; i < 'I'; ++i)
    {
        std::cout << stack.pop().character << " ";
    }
    std::cout << std::endl;

    std::cout << "stack.stackTop() = " << stack.stackTop().character << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    std::cout << "****************************************************************************" << std::endl;
}