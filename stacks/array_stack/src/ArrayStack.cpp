#include "ArrayStack.hpp"

namespace ArrayStack
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Stack::Stack() : size(0L), top(-1L), stack(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Stack::Stack(unsigned int sizeOfStack) : size(sizeOfStack), top(-1)
    {
        stack = std::make_shared<int[]>(size);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Stack::push(const int data)
    {
        if (!isFull())
        {
            stack[++top] = data;
        }
        else
        {
            std::cout << "Stack overflow" << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    int Stack::pop()
    {
        if (!isEmpty())
        {
            return stack[top--];
        }
        else
        {
            std::cout << "Stack underflow" << std::endl;
            return INT_MIN;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::peek(int index) const
    {
        return (index < size) ? stack[index] : INT_MIN;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::stackTop() const
    {
        return (stack != nullptr && top > 0L) ? stack[0] : INT_MIN;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodisacrd]] bool Stack::isEmpty() const
    {
        return (top == -1L);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isFull() const
    {
        return (top == size - 1);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Stack& s)
    {
        if (s.stack != nullptr)
        {
            for (unsigned int i = 0; i < s.size; ++i)
            {
                os << s.stack[i] << " ";
            }
        }
        
        return os;
    }

}