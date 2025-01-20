#include "ArrayQueue.hpp"

namespace ArrayQueue
{

    // Time complexity -> o(1)
    // Space complexity -> o(n) -> creating array of size arraySize
    Queue::Queue(const int size) : arraySize(size)
    {
        array = std::make_shared<int[]>(arraySize);
        front = -1L;
        rear = -1L;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Queue::enqueue(const int x)
    {
        if (!isFull())
        {
            array[++rear] = x;
        }
        else
        {
            std::cout << "Queue is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::dequeue()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = array[++front];
        }
        else
        {
            std::cout << "Stack is empty." << std::endl;
        }

        return data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isEmpty() const
    {
        return (rear == front);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isFull() const
    {
        return (rear == (arraySize - 1));
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::first() const
    {
        return array[front + 1];
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Queue::last() const
    {
        //return ((rear == arraySize) ? array[rear - 1] : array[rear]);
        return array[rear];
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Queue queue)
    {
        if (!queue.isEmpty())
        {
            for (unsigned int i = queue.front + 1; i <= queue.rear; ++i)
            {
                os << queue.array[i] << " ";
            }
        }
        else
        {
            os << "Queue is empty.";
        }

        return os;
    }
}