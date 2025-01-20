#include <iostream>
#include "ArrayStack.hpp"

int main()
{
    ArrayStack::Stack stack(10);

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

    for (unsigned int i = 0; i < 12; ++i)
    {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "stack.stackTop() = " << stack.stackTop() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    return 0;
}