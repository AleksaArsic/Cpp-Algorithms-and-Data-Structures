#include "LinkedListQueue.hpp"

namespace LinkedListQueue
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    Queue::Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void Queue::enqueue(const int x)
    {
        std::shared_ptr<Node> newNode = nullptr;

        if (!isFull())
        {
            newNode = std::make_shared<Node>(x, nullptr);
            
            if (front == nullptr)
            {
                front = newNode;
                rear = front;
            }
            else
            {
                rear->next = newNode;
                rear = rear->next;
            }
        }
        else
        {
            std::cout << "The queue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Queue::dequeue()
    {
        int data = INT_MIN;
        std::shared_ptr<Node> node = front;

        if (!isEmpty())
        {
            data = front->data;
            node = front->next;
            front.reset();
            front = node;
        }
        else
        {
            std::cout << "The queue is empty." << std::endl;
        }

        return data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Queue::isFull() const
    {
        std::shared_ptr<Node> node = std::make_shared<Node>(INT_MIN, nullptr);
        
        return (node == nullptr) ? true : false;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Queue::isEmpty() const
    {
        return (front == nullptr);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Queue::first() const
    {
        return ((front == nullptr) ? INT_MIN : front->data);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Queue::last() const
    {
        return ((rear == nullptr) ? INT_MIN : rear->data);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(n)
    std::ostream& operator<<(std::ostream& os, const Queue& queue)
    {
        std::shared_ptr<Node> node = queue.front;

        while (node != nullptr)
        {
            os << node->data << " ";
            node = node->next;
        }

        return os;
    }
}