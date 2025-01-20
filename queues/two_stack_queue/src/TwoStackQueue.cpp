#include "TwoStackQueue.hpp"

namespace TwoStackQueue
{

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Queue::enqueue(const int data)
    {
        if (!stackOne.isFull()) // o(1)
        {
            stackOne.push(data);
        }
        else
        {
            std::cout << "Queue is full." << std::endl;
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::dequeue()
    {
        int data = INT_MIN;

        while (!stackOne.isEmpty()) // o(1)
        {
            stackTwo.push(stackOne.pop()); // o(1 + 1)
        }

        if (stackTwo.stackSize() > 0) // o(1)
        {
            data = stackTwo.pop(); // o(1)
        }

        return data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isEmpty()
    {
        return (stackOne.isEmpty() && stackTwo.isEmpty()); // o(1 + 1)
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isFull()
    {
        std::shared_ptr<LinkedListStack::Node> node = std::make_shared<LinkedListStack::Node>(INT_MIN, nullptr);

        return (node == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::first()
    {
        if (stackOne.stackSize() > 0) // o(1)
        {
            return stackOne.stackTop(); // o(1)
        }
        else if (stackTwo.stackSize() > 0) // o(1)
        {
            return stackTwo.peek(stackTwo.stackSize() - 1); // o(1 + 1)
        }
        
        return INT_MIN;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::last()
    {
        if (stackOne.stackSize() > 0) // o(1)
        {
            return stackOne.peek(stackOne.stackSize() - 1); // o(1 + 1)
        }
        else if (stackTwo.stackSize() > 0) // o(1)
        {
            return stackTwo.stackTop(); // o(1)
        }

        return INT_MIN;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Queue& queue)
    {
        if (queue.stackOne.stackSize() || queue.stackTwo.stackSize()) // o(1 + 1)
        {
            os << queue.stackTwo << " " << queue.stackOne; // o(n + n)
        }
        else
        {
            os << "Queue is empty.";
        }

        return os;
    }
}