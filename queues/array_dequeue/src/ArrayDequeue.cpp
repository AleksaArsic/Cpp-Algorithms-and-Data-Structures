#include "ArrayDequeue.hpp"

namespace ArrayDequeue
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(n)
    CircularDequeue::CircularDequeue(const unsigned int size) : dequeueSize(size)
    {
        rear = 0L;
        front = 1L;

        array = std::make_shared<int[]>(dequeueSize);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void CircularDequeue::pushFront(const int data)
    {
        if (!isFull())
        {
            if (front < 0)
            {
                front = dequeueSize;
            }

            array[--front] = data;

        }
        else
        {
            std::cout << "[pushFront()] Dequeue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void CircularDequeue::pushBack(const int data)
    {
        if (!isFull())
        {
            array[rear] = data;
            rear = (rear + 1) % dequeueSize;
        }
        else
        {
            std::cout << "[pushBack()] Dequeue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int CircularDequeue::popFront()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = array[front];
            array[front] = 0;
            front = (front + 1) % dequeueSize;
        }
        else
        {
            std::cout << "[popFront()] Dequeue is empty." << std::endl;
        }

        return data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int CircularDequeue::popBack()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            rear--;
            if (rear < 0)
            {
                rear = dequeueSize - 1;
            }

            data = array[rear];
            array[rear] = 0;
        }
        else
        {
            std::cout << "[popBack()] Dequeue is empty." << std::endl;
        }

        return data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int CircularDequeue::first() const
    {
        return (isEmpty() ? INT_MIN : array[front]);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int CircularDequeue::last() const
    {
        return (isEmpty() ? INT_MIN : array[rear - 1]);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool CircularDequeue::isFull() const
    {
        return (((front + 1) % dequeueSize) == front);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool CircularDequeue::isEmpty() const
    {
        return (rear == front);
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const CircularDequeue& dequeue)
    {
        for (unsigned int i = 0; i < dequeue.dequeueSize; ++i)
        {
            os << dequeue.array[i] << " ";
        }

        return os;
    }
}