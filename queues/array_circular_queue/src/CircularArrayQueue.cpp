#include "CircularArrayQueue.hpp"

namespace CircularArrayQueue
{
    // Time complexity -> o(1)
    // Space complexity -> o(n) -> creating array of size arraySize
    CircularQueue::CircularQueue(const int size) : arraySize(size)
    {
        array = std::make_shared<int[]>(arraySize);
        front = 0L;
        rear = 0L;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    // One place shall remain empty as we don't want rear and front to come together
    // If they are on the same index, the circular queue is empty
    void CircularQueue::enqueue(const int x)
    {
        if (!isFull())
        {
            array[rear] = x;
            rear = ((rear + 1) % arraySize);
        }
        else
        {
            std::cout << "Circular queue is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    [[nodiscard]] int CircularQueue::dequeue()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = array[front];
            front = ((front + 1) % arraySize);
        }
        else
        {
            std::cout << "Circular queue is empty." << std::endl;
        }

        return data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    [[nodiscard]] bool CircularQueue::isEmpty() const
    {
        return (front == rear);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    // One place shall remain empty as we don't want rear and front to come together
    // If they are on the same index, the circular queue is empty
    [[nodiscard]] bool CircularQueue::isFull() const
    {
        return (((rear + 1) % arraySize) == front);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    [[nodiscard]] int CircularQueue::first() const
    {
        return array[front];
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1) 
    [[nodiscard]] int CircularQueue::last() const
    {
        return array[rear - 1];
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1) 
    std::ostream& operator<<(std::ostream& os, const CircularQueue cq)
    {
        if (!cq.isEmpty())
        {
            for (unsigned int i = cq.front; i < cq.rear; ++i)
            {
                os << cq.array[i] << " ";
            }
        }
        else
        {
            os << "Circular queue is empty.";
        }
        

        return os;
    }
}